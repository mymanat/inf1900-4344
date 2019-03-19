#ifndef MOTEURS_H
#define MOTEURS_H
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include "PWM.h"
#include "Utils.h"


#define MOTEUR_DROITE 1
#define MOTEUR_GAUCHE 0

#define DIRECTION_AVANCER 1
#define DIRECTION_RECULER 0

#define VITESSE_ROTATION 255
#define DUREE_ROTATION 500
class moteurs {
public:
    moteurs();

    void ajustementPWM(int a, int b);
    void avancer(int vitesse);
    void reculer(int vitesse);
    void tournerDroite();
    void tournerGauche();
    void arreterMoteurs();


    void setDirectionMoteur(bool direction, bool moteurNb);

    void setDirection(bool direction);


};

#endif
