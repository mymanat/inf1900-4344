#ifndef MOTEURS_H
#define MOTEURS_H
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include "PWM.h"
#include "Utils.h"
#include "Component.h"

#define MOTEUR_DROITE 1
#define MOTEUR_GAUCHE 0

#define DIRECTION_AVANCER 1
#define DIRECTION_RECULER 0

#define VITESSE_ROTATION 100
#define DUREE_ROTATION 500

#define TEMPS_ROTATION_90 1000
#define COEFFICIENT_MOTEUR_TROP_VITE 0.98

#define VITESSE_MAX 170
#define VITESSE_LENT 130
#define VITESSE_MAX_ULTRA 220

class moteurs : public Component
{
  public:
    moteurs();

    void init() override;

    void ajustementMoteur(uint8_t gauche, uint8_t droite);
    void avancer(int vitesse);
    void reculer(int vitesse);
    void tournerDroite();
    void tournerGauche();
    void arreterMoteurs();
    void tournerDroite90();
    void tournerGauche90();

    void setDirectionMoteur(bool direction, bool moteurNb);

    void setDirection(bool direction);

  private:
    void ajustementPWM(uint8_t a, uint8_t b);
};

#endif
