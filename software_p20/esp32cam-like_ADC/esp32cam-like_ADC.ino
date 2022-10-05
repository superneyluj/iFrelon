// I2C
#define SDA  33
#define SCL  32
#include <Wire.h>
#include <MCP342x.h>
// 0x68 is the default address for all MCP342x devices
//uint8_t address = 0x6A; //range 0x68 - 0x6F (inclusive)
MCP342x adc = MCP342x(); //(address);

#include <Adafruit_PWMServoDriver.h> //You can download this library below


//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();  //set default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); //(0x40, Wire);


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




void setup() {
  Serial.begin(115200);
  Serial.println("\ntest ADC");
  
  Wire.begin(SDA, SCL);
  
  pwm.begin();
  pwm.setPWMFreq(100);  // maximum PWM frequency 1600
  
  // LED
  Serial.println("begin led test");
  pwm.setPin(PCA_LED_R,PIN_OFF,true); // true to invert because leds are connected between VCC and output. 
  pwm.setPin(PCA_LED_G,PIN_ON,true);
  delay(1000);
  pwm.setPin(PCA_LED_G,PIN_OFF,true);
  pwm.setPin(PCA_LED_R,PIN_ON,true);
  delay(1000);
  pwm.setPin(PCA_LED_R,PIN_OFF,true);
  Serial.println("end led test");

  // power camera
  pwm.setPin(PCA_POWER_SD,PIN_OFF,false);
  pwm.setPin(PCA_POWER,PIN_ON,false);
  pwm.setPin(PCA_LED_R,PIN_OFF,true);
  pwm.setPin(PCA_LED_G,PIN_OFF,true);
  
//  // Reset devices
//  MCP342x::generalCallReset();
//  delay(1); // MC342x needs 300us to settle, wait 1ms
//  // Check device present
//  Wire.requestFrom(address, (uint8_t)1);
//  if (!Wire.available()) {
//    Serial.print("No device found at address ");
//    Serial.println(address, HEX);
//  }


  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
  nDevices = 0;
  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
      nDevices++;
    }
    else if (error==4) {
      Serial.print("Unknow error at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
    }  
    delayMicroseconds(100);  
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  } else {
    Serial.println("done\n");
  }

}

void loop() {
  pwm.setPin(PCA_LED_R,PIN_OFF,true); // true to invert because leds are connected between VCC and output. 
  pwm.setPin(PCA_LED_G,PIN_ON,true);
  Serial.println("GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG");
  delay(1000);
  pwm.setPin(PCA_LED_G,PIN_OFF,true);
  pwm.setPin(PCA_LED_R,PIN_ON,true);
  Serial.println("RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR");
  delay(1000);


  long value = 0;
  MCP342x::Config status;
  // Initiate a conversion; convertAndRead() will wait until it can be read
  uint8_t err = adc.convertAndRead(MCP342x::channel2, MCP342x::oneShot,
           MCP342x::resolution12, MCP342x::gain1,
           1000000, value, status);
  if (err) {
    Serial.print("Convert error: ");
    Serial.println(err);
  }
  else {
    Serial.print("Value: ");
    Serial.println(value);
  }
}
