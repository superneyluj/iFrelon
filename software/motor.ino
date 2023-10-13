#include <Wire.h>

// Include Adafruit PCA9685 Servo Library
#include <Adafruit_PWMServoDriver.h>

// Creat object to represent PCA9685 at default I2C address
Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(0x40);

// Define maximum and minimum number of "ticks" for the servo motors
// Range from 0 to 4095
// This determines the pulse width

#define SDA 26
#define SCL 27 

//Valeur 0° 90° 180° moteur vertical
#define SERVOMIN_1  100  // Minimum value
#define SERVOMAX_1  520  // Maximum value
#define SERVOMID_1  310  // Middle value

//Valeur 0° 90° 180° moteur horizontal
#define SERVOMIN_2  125  // Minimum value
#define SERVOMAX_2  455  // Maximum value
#define SERVOMID_2  280  // Middle value

// Define servo motor connections (expand as required)
#define SER0  0   //Servo Motor 0 on connector 0 horizontal
#define SER1  1  //Servo Motor 1 on connector 12 vertical

// Variables for Servo Motor positions (expand as required)
int pwm0;
int pwm1;

void setup() {

  // Serial monitor setup
  Wire.begin(SDA , SCL);
  Serial.begin(115200);

  // Print to monitor
  Serial.println("PCA9685 Servo Test");

  // Initialize PCA9685
  pca9685.begin();

  // Set PWM Frequency to 50Hz
  pca9685.setPWMFreq(50);

  pca9685.setPWM(SER0, 0,SERVOMID_2 );
  Serial.println(SERVOMID_2);
  delay(2000);

  pca9685.setPWM(SER1, 1,SERVOMID_1 );
  Serial.println(SERVOMID_1);
  delay(2000);

}

void loop() {
//Offset de 6 degrés angle à 90 degres => 84° pour horizontal

  // MIN Moteur vertical
  // int lowAngle = map(85,0,180,SERVOMIN_1,SERVOMAX_1);
  // pca9685.setPWM(SER1, 1,lowAngle);
  // Serial.println(lowAngle);
  // delay(2000);

  // // MID Moteur vertical
  

  // // MAX Moteur vertical
  // int MidAngle3 = map(84,0,180,SERVOMIN_2,SERVOMAX_2);
  // pca9685.setPWM(SER0, 0,MidAngle3);
  // Serial.println(MidAngle3);
  // delay(2000);

  // int MidAngle4 = map(100,0,180,SERVOMIN_1,SERVOMAX_1);
  // pca9685.setPWM(SER1, 1,MidAngle4 );
  // Serial.println(MidAngle4);
  // delay(2000);

  // int MidAngle6 = map(90,0,180,SERVOMIN_1,SERVOMAX_1);
  // pca9685.setPWM(SER1, 1,MidAngle6 );
  // Serial.println(MidAngle6);
  // delay(2000);

  // int MidAngle2 = map(74,0,180,SERVOMIN_2,SERVOMAX_2);
  // pca9685.setPWM(SER0, 0,MidAngle2);
  // Serial.println(MidAngle2);
  // delay(2000);

  // int MidAngle1 = map(95,0,180,SERVOMIN_1,SERVOMAX_1);
  // pca9685.setPWM(SER1, 1,MidAngle1 );
  // Serial.println(MidAngle1);
  // delay(2000);

  // int MidAngle5 = map(94,0,180,SERVOMIN_2,SERVOMAX_2);
  // pca9685.setPWM(SER0, 0,MidAngle5);
  // Serial.println(MidAngle5);
  // delay(2000);

  // pca9685.setPWM(SER1, 1,MidAngle4 );
  // Serial.println(MidAngle4);
  // delay(2000);

  // //MIN Moteur horizontal
  // // pca9685.setPWM(SER0, 0,SERVOMIN_2 );
  // // Serial.println(SERVOMIN_2);
  // // delay(5000);

  //MID Moteur horizontal
  
  
  //MAX Moteur horizontal
  // pca9685.setPWM(SER0, 0,SERVOMAX_2 );
  // Serial.println(SERVOMAX_2);
  // delay(5000);
 
}


