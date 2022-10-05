#include "esp_camera.h"
#include <WiFi.h>
// I2C
#define SDA  33
#define SCL  32
#include <Wire.h>

#include <Adafruit_PWMServoDriver.h> //You can download this library below

//
// WARNING!!! PSRAM IC required for UXGA resolution and high JPEG quality
//            Ensure ESP32 Wrover Module or other board with PSRAM is selected
//            Partial images will be transmitted if image exceeds buffer size
//

// Select camera model
//#define CAMERA_MODEL_WROVER_KIT // Has PSRAM
//#define CAMERA_MODEL_ESP_EYE // Has PSRAM
//#define CAMERA_MODEL_M5STACK_PSRAM // Has PSRAM
//#define CAMERA_MODEL_M5STACK_V2_PSRAM // M5Camera version B Has PSRAM
//#define CAMERA_MODEL_M5STACK_WIDE // Has PSRAM
//#define CAMERA_MODEL_M5STACK_ESP32CAM // No PSRAM
#define CAMERA_MODEL_AI_THINKER // Has PSRAM
//#define CAMERA_MODEL_TTGO_T_JOURNAL // No PSRAM

#include "camera_pins.h"

//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();  //set default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);

#if defined(ARDUINO_ARCH_SAMD)  
// for Zero, output on USB Serial console, remove line below if using programming port to program the Zero!
   //#define Serial SerialUSB
#endif

// PCA9685
#define PCA_M1       0
#define PCA_M2       1
#define PCA_POWER    2
#define PCA_POWER_SD 3
#define PCA_15       8
#define PCA_16       9
#define PCA_17      10
#define PCA_18      11
#define PCA_19      12
#define PCA_20      23
#define PCA_LED_R   14
#define PCA_LED_G   15
enum pin_state {PIN_OFF=0, PIN_ON=4095};

const char* ssid = "dlink-E05F";

const char* password = "kuhcz80763";

void startCameraServer();

void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println("test");
  
  //Wire.begin(26, 27); // Set if your using can use any two pins > SDA to #2 and SCL to #14
  Wire.begin(SDA, SCL);
  
  delay(4000);
  pwm.begin();
  pwm.setPWMFreq(1600);  // Set  This is the maximum PWM frequency
  
  // LED
  
  pwm.setPin(PCA_LED_R,PIN_OFF,true); // true to invert because leds are connected between VCC and output. 
  pwm.setPin(PCA_LED_G,PIN_ON,true);
  delay(1000);
  pwm.setPin(PCA_LED_G,PIN_OFF,true);
  pwm.setPin(PCA_LED_R,PIN_ON,true);
  delay(1000);
  pwm.setPin(PCA_LED_R,PIN_OFF,true);

  // power camera
  pwm.setPin(PCA_POWER_SD,PIN_OFF);
  pwm.setPin(PCA_POWER,PIN_ON);
  pwm.setPin(PCA_LED_R,PIN_OFF,true);
  pwm.setPin(PCA_LED_G,PIN_OFF,true);
  
  // if you want to really speed stuff up, you can go into 'fast 400khz I2C' mode
  // Note some i2c devices dont like this so much so if you're sharing the bus
//  #ifdef TWBR     // Set save I2C bitrate
//  uint8_t twbrbackup = TWBR;  
//  // must be changed after calling Wire.begin() (inside pwm.begin())
//  TWBR = 12; // upgrade to 400KHz!
//  #endif
  //pwm.setPin(2, 4095,0);

  
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 10000000;
  config.pixel_format = PIXFORMAT_JPEG;
  
  // if PSRAM IC present, init with UXGA resolution and higher JPEG quality
  //                      for larger pre-allocated frame buffer.
  if(psramFound()){
    config.frame_size = FRAMESIZE_UXGA;
    config.jpeg_quality = 10;
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_SVGA;
    config.jpeg_quality = 12;
    config.fb_count = 1;
  }

#if defined(CAMERA_MODEL_ESP_EYE)
  pinMode(13, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
#endif
  
  // camera init
  esp_err_t err = esp_camera_init(&config);
  Serial.println("Camera initialisee");

  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }
  
  sensor_t * s = esp_camera_sensor_get();
  // initial sensors are flipped vertically and colors are a bit saturated
  if (s->id.PID == OV3660_PID) {
    s->set_vflip(s, 1); // flip it back
    s->set_brightness(s, 1); // up the brightness just a bit
    s->set_saturation(s, -2); // lower the saturation
  }
  // drop down frame size for higher initial frame rate
  s->set_framesize(s, FRAMESIZE_QVGA);

#if defined(CAMERA_MODEL_M5STACK_WIDE) || defined(CAMERA_MODEL_M5STACK_ESP32CAM)
  s->set_vflip(s, 1);
  s->set_hmirror(s, 1);
#endif

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  startCameraServer();

  Serial.print("Camera Ready! Use 'http://");
  Serial.print(WiFi.localIP());
  Serial.println("' to connect");
}

void loop() {
}
