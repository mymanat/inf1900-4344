#ifndef MOTEURS_H
#define MOTEURS_H
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include "PWM.h"
class moteurs {
public:
    moteurs();

    void ajustementPWM(int a, int b);
    void avancer(int vitesse);
    void reculer(int vitesse);
    void tournerDroite();
    void tournerGauche();
    void arreterMoteurs();


};

#endif
