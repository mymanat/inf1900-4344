#ifndef MOTEURS_H
#define MOTEURS_H
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include "PWM.h"
class moteurs {
public:
    moteurs();

<<<<<<< HEAD
void ajustementPWM(int a, int b);
void avancer(int vitesse);
void reculer(int vitesse);
void tournerDroite();
void tournerGauche();
void arreterMoteurs();
=======
    void ajustementPWM(int a, int b);
    void avancer(int vitesse);
    void reculer(int vitesse);
    void tournerDroite();
    void tournerGauche();
    void arreterMoteurs();


};
>>>>>>> 0cac7c03faa3d34a5b7b3148574f7ae8b704e970

#endif
