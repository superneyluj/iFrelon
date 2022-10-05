Semaine 1 
-

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

Semaine 2 
-

Tâches effectuées:
- Test du code sur le laser -> OK 
- Montage du moteur sur support 
- Pour la partie intégration, on fait bouger la caméra avec le laser (le plan change tout le temps et plus de problème de Z)
- Changement de module de caméra 

Semaine 3
-
(Julien absent)
Tâches effectuées :
- avancement du code du moteur, rédaction des fonctions suivantes :
    - conversion de X,Y pour remettre à l'échelle réelle (pixel -> angle)
    - move_moteur pour le faire bouger grâce aux coordonnées
-