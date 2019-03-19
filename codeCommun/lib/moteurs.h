#ifndef MOTEURS_H
#define MOTEURS_H
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

<<<<<<< HEAD
void initialisationMoteurs();
void ajustementPWM(int pa, int pb);
=======
void ajustementPWM(int a, int b);
void avancer(int vitesse);
void reculer(int vitesse);
void tournerDroite();
void tournerGauche();
void arreterMoteurs();

#endif
>>>>>>> 38d1c7dd06c9fe5dc5cef99c62098322459e11f5
