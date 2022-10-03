

#include <Servo.h> 
float pixel_axe_X = 800;
float pixel_axe_y = 600;
float angle_camera_X = 66;
float angle_camera_Y = 50;
void move_moteur(float coordX, float coordY);
float current_angleX = 0;
float current_angleY = 0;
float init_coordX=90;
float init_coordY=90;
int time_shoot = 2000;
int laserPin = A2;
int angleMaxX = 60;
int angleMaxY = 60;

float conversion_coord_deg(float coord, float minPixel, float maxPixel, float minAngle, float maxAngle);
void return_to_initial_coords();
Servo servo1; // Axe X
Servo servo2; //Axe Y
float angleX = 0;
float angleY = 0;

void setup() {
  servo1.attach(3);
  servo2.attach(9);
  servo1.write(init_coordX);
  servo2.write(init_coordY);
  pinMode(laserPin,OUTPUT);
   //digitalWrite(laserPin, HIGH);
  delay(3000);
  Serial.begin(9600); 
}

/*void loop() {
 move_moteur(-300,-200);
  shoot(2000);
  
  return_to_initial_coords();
  delay(2000);
  

}*/

void loop(){
  if(1){
    decision();
   }
}

void move_moteur(float coordX, float coordY){
  // 90 < angleY < 180
  float angleX = current_angleX + conversion_coord_deg(coordX,-pixel_axe_X/2,pixel_axe_X/2,-angle_camera_X/2,angle_camera_X/2);
  float angleY = current_angleY + conversion_coord_deg(coordY,-pixel_axe_y/2,pixel_axe_y/2,-angle_camera_Y/2,angle_camera_Y/2);
   
  //Gestion des angles maximums
  if(angleX > angleMaxX)angleX = angleMaxX;
  if(angleX < -angleMaxX)angleX = -angleMaxX;
  if(angleY > angleMaxY)angleY= angleMaxY;
  if(angleY < -angleMaxY)angleY = -angleMaxY;

  //On bouge les moteurs
  servo1.write((angleX)+90); 
  servo2.write(-(angleY)+90);

  //le current_angle devient prend la valeur du dernier angle calculé 
  current_angleX = angleX;
  current_angleY = angleY;
  
}

float conversion_coord_deg(float coord, float minPixel, float maxPixel, float minAngle, float maxAngle){
  return (coord - minPixel) * (maxAngle - minAngle) / (maxPixel - minPixel) + minAngle;
}

void return_to_initial_coords(){
  servo1.write(init_coordX);
  servo2.write(init_coordY);
  current_angleX = 0;
  current_angleY = 0;
  
}



void decision(){
    /*int x1 = coordFromCameraX();
    int y1 = coordFromCameraY();*/

    int x1 = 300;
    int y1 = 300;

    move_moteur(x1,y1);

    /*int x2 = coordFromCameraX();
    int y2 = coordFromCameraY();*/

    int x2 = 300;
    int y2 = 300;
    if(x2 - x1 < 0.1 && y2 - y1 < 0.1){
      shoot(time_shoot);
      return_to_initial_coords();
      delay(1000); //Delay pour laisser au moteur le temps de revenir au coord initiales

      
    }else{
      Serial.println("Decision()");
      decision();
    } 
}


void shoot(int time_shoot) {
  digitalWrite(laserPin, HIGH);
  delay(time_shoot);
  digitalWrite(laserPin, LOW);
}

  
