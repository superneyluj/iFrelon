***Cahier de suivi***
==

-----------------------------------------------------------------------------------------------------------------------------------------------------

Semaine 1 
-

Découverte du projet tous ensemble

Tâches effectuées: 
- Création du Github et d'un fichier .md pour chacun
- Brainstorming
- Définition des tâches à effectuer puis répartition :
  --> Carte électronique
  --> Laser
  --> Détection sonore
  --> Traitement de l'image 
  --> Moteurs pour le laser 

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

-----------------------------------------------------------------------------------------------------------------------------------------------------

Semaine 2 
-

Réflexion sur la carte de développement à choisir 

Tâches effectuées:
- Mise en place des fichiers manquant dans la librairi 
- Test des codes sur la carte développé les années précédentes
  -esp32cam-like_ADC ok
  -esp32cam-lik...eraWebServer non
  -esp32cam-like_SD non
- Choix d'une nouvelle carte ESP32 ayant assez de pin pour tous les élements 
https://fr.aliexpress.com/item/1005004339923548.html?spm=a2g0o.productlist.0.0.c8cf6580DWV1cv&algo_pvid=f372cd97-2c25-4022-8957-f011c3396965&algo_exp_id=f372cd97-2c25-4022-8957-f011c3396965-43&pdp_ext_f=%7B%22sku_id%22%3A%2212000028820495478%22%7D&pdp_npi=2%40dis%21EUR%219.45%219.45%21%21%213.93%21%21%402100bb5116627319091174163ef6e8%2112000028820495478%21sea&curPageLogUid=yXEbJDUEzOyp
- Commande de deux cartes de développement ESP32
- Décision de mettre le module SD sur une carte externe communication par protocole SPI avec l'ESP32


-----------------------------------------------------------------------------------------------------------------------------------------------------

Semaine 3
-

Réflexion sur le module de développement (en attente de réception)

Tâches effectuées :
- Réflexion sur les codes exemples existant 
- Travail sur les fonctions de conversion de X,Y en angulaire
- Recherche et compréhension de la mémoire Interne de ESP32 
- Définition du procésus pour la partie code
  - Prise de la photo
  - Stockage dans ESP32 de l'image 
  - Traitement de l'image 
  - Calucl des X, Y ou angle
  - Mise en route du moteur 
  - Tir du laser 
  
-----------------------------------------------------------------------------------------------------------------------------------------------------

Semaine 4 :
-

Tâches effectuées :
- Réception de la nouvelle carte ESP32 et mise à jour du fichier de mapping de la Carte ESP32-WROVER dev afin de faire un point sur les entrées et sortis disponibles pour brancher nos composants externes
- Installation des pilotes nécessaires pour la carte 
- Mise en ouevre des codes Blink / CameraWebServer / VideoWebServer pour comprendre le focntionnement de la caméra   
- Branchement d'un module de carte SD 
- Branchement du module sur des I/O disponibles 
- Mise en oeuvre d'un code ESP32_SD_V3 qui permet de définir le protocole de communication SPI, de créer un fichier pour l'enregistrer sur la carte SD 

Objectif de la prochaine séance: réussir à stocker une photo sur la carte sd / créer un code regroupant le tout 
Essayer de brancher un composant I2C 

-----------------------------------------------------------------------------------------------------------------------------------------------------

Semaine 5:
-

Paramètres de la carte :  Type de carte : ESP32 - Wrover Module
                          Upload speed 115200
                          Flash frequency 80 Mhz
                          Partion schema : Huge App
                          
https://randomnerdtutorials.com/esp32-cam-take-photo-save-microsd-card/                    
                          
- Ajustement de la gestion des pins disponibles pour permettre au module SD et la caméra de fonctionner ensemble
- Création du code permettant de prendre une photo et de la stocker sur la carte SD voir code main_v1.h dans software 
- Reconnaissance d'un écran LCD grâce au protocole I2C nous avons pour cela utiliser les sorties I2C de l'ESP32 et réalisé un SCAN afin d'identifier l'adresse du module 

Objectif de la prochaine séance: intégrer l'écran LCD au code existant et y faire afficher l'image, prévoir une synoptique d'une carte électronique à réaliser pour compiler toutes les sorties.

-----------------------------------------------------------------------------------------------------------------------------------------------------

Semaine 6 :
-

Partie code : 
- Mise en oeuvre de l'écran I2C sur les pins SDA et SCL du freenove 
- Mise en place du code permettant de regouprer la prise de la photo, le module I2C ainsi que le le module carte SD
- Finalisation de la séance par la création du Soft main_V2 
- Le code main_V2 permet de prendre une photo toutes les seconde, la stock sur la carte sd et affiche du texte sur un écran en I2C. Pas de conflit
Utilisation de la librairie : ESP8266 and ESP32 OLED driver

Objectif de la prochaine séance : concevoir une carte électronique avec le freenove / le module SD / le convertisseur analogique numérique / les LEDS

-----------------------------------------------------------------------------------------------------------------------------------------------------

Semaine 7 :
-

Cours en visio 
Conception de la carte électronique sur EasyEda
-Mise en place des librairies
-Recherche des composants 
-conception du schèma 
-vérification et approbation par M Peter 

-----------------------------------------------------------------------------------------------------------------------------------------------------

Semaine 8 :
-

-Finalisation du routage de la carte 
-Création du auvent au FabLab (reflexion, conception, réalisaton) découpe du bois, des tasseaux etc 

-----------------------------------------------------------------------------------------------------------------------------------------------------

Semaine 9 :
-

-Finalisation de la conception du auvent (création de la boite sur le coté pour y fixer la carte et les moteurs)
-Test d'une carte similaire à Freenove 
-Création du fichier regroupant tous les composants de la carte éléctronique 

-----------------------------------------------------------------------------------------------------------------------------------------------------

Semaine 10:
-

-Récéption de la carte élétronique 
-Désousadage des composants sur anciennes carte du projet
-Soudure des nouveaux composants CMS sur cartes avec four au FabLab 
-Soudure des composants Freenove, module SD et header 
-Test de la carte 
  Programme pour les LEDs (clignotement, chenillard ...)
  Programme pour l'ADC avec une photo-résitance
 
 



