# Épreuve Finale: INF1900

Par:

Maxime Fecteau 1958409

Simon Malouin 1958591

Samuel Poulin 1960424

Simon Tran: 1961279


-------------------------

La librairie se trouve dans le dossier "lib". Pour la compiler, naviguez dans ce dossier et exécutez

    make

Le code du projet ce trouve dans le dossier "projet_final".

    make          #Pour compiler
    make install  #Pour compiler et installer 
    make debug    #Pour compiler et installer en mode debug
    
Il est possible de compiler la librairie et de compiler le projet en mode debug avec une seule commande. Pour ce faire, mettez le fichier "install_script.sh" en mode exécutable:

    chmod +x install_script.sh
    
Ensuite, exécutez un "make" dans le même répertoire


--------------

Le dossier "robot2" contient le code du robot émetteur.

Le dossier "robot1" contient le code du robot qui effectue le parcourt.

----

Le "main" du robot1 crée un objet "Robot1" en fonction de la section à effectuer. Les classes "Section1", "Section", "Section3" et "Section4" dérivent tous de "Robot1".


La classe Robot1 étant parente à toutes les classes de section, elle s'occupe de définir plusieurs méthodes et attributs communs aux sections.

Elle s'occupe de définir entre autre la boucle d'exécution principale. Il suffit d'appeler la fonction "run()" d'un objet de type Robot1 pour que celui-ci exécute son parcourt.
Cette méthode contient la boucle principale. Elle possède 3 étapes:

1. Elle met à jour les capteurs de lignes et les DELs.
2. Elle détermine l'action à effectuer en fonction de l'état de la machine à état en appelant la méthode virtuelle "evaluateAction()" qui est redéfinit par les classes de section
3. Elle détermine si la machine à état devrait changer d'état.



----
#ROBOT 2: Robot Émetteur

Lorsque le robot est pret à transmettre, la DEL se trouvant sur la carte s'allume.

Lorsque l'on appuie sur le bouton poussoir, elle change de couleur.

Après 2 secondes, si l'utilisateur a arrêter d'appuyer à répétition sur le bouton, le signal est transmit. Pendant la transmission,
la DEL devient rouge. Ensuite, elle va cligneter un nombre de fois correspondant au signal envoyé.
