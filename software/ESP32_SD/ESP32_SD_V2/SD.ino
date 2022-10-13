/*********
Projet HORNETKILLER POLYTECH 2021
*********/

#include <SPI.h> 
#include <SD.h>


#define MOSI 14
#define MISO 4
#define CLK 13
#define SS 32


//Pin numbers des éléments 
File logfile;


//....................................................//

void setup() {

   Serial.begin(115200);
   delay(5000);
 
   Serial.println("Début config");
   SPI.begin(CLK, MISO, MOSI, SS);

   
   //Initialisation Carte SD 
   Serial.println("Initializing SD card...");
  
   // see if the card is present and can be initialized:
   if (!SD.begin(SS)) {
      Serial.println("Card failed, or not present");
   }
   
   Serial.println("card initialized.");
  
   char filename[] = "LOGGER00.CSV";
   for (uint8_t i = 0; i < 100; i++) {
      filename[6] = i/10 + '0';
      filename[7] = i%10 + '0';
      if (! SD.exists(filename)) {
        // N'ouvrir un nouveau fichier que s il n'existe pas
        logfile = SD.open(filename, FILE_WRITE); 
        break;  // quiter la boucle
      }
   }
 
    if (! logfile) {
       Serial.println("Ne peut pas creer le fichier");
    }
    Serial.print("Enregistrer dans : ");
    Serial.println(filename);
  
    logfile.print("Time(s)");
    logfile.print(";");
    logfile.print("TMP117(0-Pouce)");
    logfile.print(";");
    logfile.print("TMP117(1-Index)");
    logfile.print(";");
    logfile.print("TMP117(2-Majeur)");  
    logfile.print(";");
    logfile.print("TMP1178(4-Annulaire)");
    logfile.print(";");
    logfile.print("TMP117(5-Auriculaire)");
    logfile.print(";");
    logfile.print("TMP117(6-Pomme de la main)");  
    logfile.print(";");
    logfile.print("TMP1178(7-Dessus de la main)");
    logfile.println();  
  
   Serial.println("Initialisation terminée"); // Create a new line for the loop for easier readings
   Serial.println("/--------------------------------------------------/");
}



//....................................................//

void loop() {
 
}
