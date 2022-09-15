Cahier de suivi
==

-----------------------------------------------------------------------------------------------------------------------------------------------------

Semaine 1 

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

Semaine 4
