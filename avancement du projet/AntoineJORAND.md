Semaine 1 
-

Tâches effectuées :
- Prise de connaissance des différents projets proposés et affectations des groupes.
- Création du Github et d'un fichier .md pour chacun
- Nous avons commencé à découper notre projet en différentes épaptes pour se répartir le travail :
  --> Carte électronique (test de la carte designée par le groupe de l'année précédente)
  --> Laser
  --> Détection sonore (réveil du système sur détection sonore de la présence d'un frelon)
  --> Traitement de l'image (détection d'un frelon sur une photo)
  --> Moteurs pour le laser (déplacement du laser sur les coordonnées du frelon dans l'espace)

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
  
Point à voir lors de la séance suivantes :
- Finir de tester l'ancienne carte pour vérifier que tous les modules fonctionnent (carte SD, caméra ...)


Semaine 2   sonore c'est non
-

Tâches effectuées:
- La partie de la détection sonore est a mettre de côté pour le moment. Priorité sur le module de détection des frelons par analyse d'image.
- Nous avons testé le laser.
- Le moteur à été monté sur un support pour commencencer et début d'écriture du code pour commander son mouvement.
- Pour la partie intégration, on fait bouger la caméra avec le laser (le plan change tout le temps et plus de problème de Z).
- Changement de module de caméra 


Semaine 3
-
(Julien absent)
Tâches effectuées :
- avancement du code du moteur, rédaction des fonctions suivantes :
    - conversion de X,Y pour remettre à l'échelle réelle (pixel -> angle)
    - move_moteur pour le faire bouger grâce aux coordonnées
-


Semaine 4
-
- Nous avons reçu la nouvelle carte ESP32-WROVER dev
- Branchement d'un module carte SD
- Test du module de caméra avec les codes de tests. Nous avons récupéré l'image de la caméra sur un serveur web.
--> Nous avons réussi à faire du transfert de donnée sur la carte sd.

Prochaine séance : réussir à stocker une photo sur la carte sd.


Semaine 7
-
Nous avons réparti les tâches en deux groupes. Un groupe travaillait sur la carte freenove, l'autre sur le code de l'analyse d'image sur ESP-32.  
- Analyse d'image sur ESP-32 :  
Nous avons commencé à étudier la piste que l'on nous a donné : https://eloquentarduino.com/portfolio/esp32-cam-image-recognition/  
C'est un projet d'EloquentArduino qui a travaillé sur la détection d'objet avec un ESP-32, qui pourrait nous permettre de faire de la reconnaissance de frelon (et ainsi ne pas les confondres avec des abeilles).  
Dans un premier temps, l'objectif serait de faire un test en entrainant l'algo avec une forme simple pour voir si c'est une solution viable.  

Cependant, il nous restera probablement le problème de la position du frelon à determiner.

Prochaine séance : Finir de mettre en place la détection de frelon + entrainement sur une forme simple.

