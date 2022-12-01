 **Projet Hornet Killer** 
- 
* 1er septembre.
  - Création du Github et d'un fichier .md pour chacun
  - Brainstorming
  - Définition des tâches à effectuer puis répartition :
    1. Carte électronique
    2. Laser
    3. Détection sonore
    4. Traitement de l'image 
    5. Moteurs pour le laser
  - Test de la carte électronique du groupe de l'année précédente
  - Partie software :
    - blocage sur un fichier .h introuvable
    - mauvaise version de librairie
  - Partie hardware:
    - carte sous alimentée (2,8V)
    - carte SD non utilisable directement sur la carte électronique, y ajouter un module SPI
    - Soudure du module SPI
* 2 septembre
* 9 septembre
* 15 septembre
* 3 octobre
* 13 octobre
* 28 octobre
* 18 novembre
* 25 novembre
* 1er décembre













Séance 1 


- Test de la carte électronique du groupe de l'année d'avant

Partie code :
  --> blocage sur un fichier .h non trouvable
  --> mauvaise version de librairie

Partie hardware :
  --> carte sous-alimentée 2.8 V
  --> carte SD non utilisable directement sur la carte électronique, y ajouter un module SPI
  --> Soudure du module SPI
 
 - Commencement de la partie moteur 
  --> Test du moteur et montage du moteur
 - Commencement de la partie Laser
  --> Trouver un code pour tester le laser 
  
Tâches à effectuer :
- Avancer sur les tests de la carte électronique

Semaine 2 

Partie hardware : 
  --> Tentative de faire fonctionner la carte de la p20, nous avons réussi à faire fonctionner la partie conversion analogique/numérique.
  mais impossible de faire fonctionner la partie caméra. 
  --> Etude de la possibilité de réaliser le projet sur une autre carte. Nous avons trouvé celle ci : 
  https://fr.aliexpress.com/item/1005004552128137.html?spm=a2g0o.order_list.0.0.66fb5e5b0Gbgdr&gatewayAdapt=glo2fra
  elle embarque la caméra nativement, et elle possède des i/o libres afin de pouvoir utiliser les moteurs, le laser et une carte sd.
  
Semaine 3 :
Partie hardware : 
--> Mapping des i/o de la carte Carte ESP32-WROVER dev sur un fichier excel. Lecture de documentation

Semaine 4 :
Partie hardware : 
--> Réception de la carte et dernière mise au point du fichier de mapping de la Carte ESP32-WROVER dev
--> Branchement d'un module carte SD 
Partie code :
--> Nous avons réussi à faire fonctionner la caméra grâce à un server web sur un téléphone
--> Nous avons réussi à faire du transfert de donnée sur la carte sd.

Prochaine séance : réussir à stocker une photo sur la carte sd.

Semaine 5 :
Paramètres de la carte :  Type de carte : ESP32 - Wrover Module
                          Upload speed 115200
                          Flash frequency 80 Mhz
                          Partion schema : Huge App
Partie code :
--> Code qui permet de prendre une photo
--> Prise d'une photo et transfert vers une carte SD
--> Reconnaissance d'un écran LCD grâce au protocole I2C

Prochaine séance : faire fonctionner l'i2c en même temps que la prise de photo pour observer un éventuel conflit

Semaine 6 :
Partie code : 
--> Le code main_V2 permet de prendre une photo toutes les seconde, la stock sur la carte sd et affiche du texte sur un écran en I2C. Pas de conflit
Utilisation de la librairie : ESP8266 and ESP32 OLED driver

Prochaine séance : faire une carte avec le freenove, la carte sd et le convertisseur analogique numérique
