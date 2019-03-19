#include "moteurs.h"

void moteurs::ajustementPWM(int a, int b) {
  // mise à un des sorties OC1A et OC1B sur comparaison

  // réussie en mode PWM 8 bits, phase correcte

  // et valeur de TOP fixe à 0xFF (mode #1 de la table 17-6

  // page 177 de la description technique du ATmega324PA)

  OCR1A = a;

  OCR1B = b;

  // division d'horloge par 8 - implique une frequence de PWM fixe

  TCCR1A = (1 << WGM10) | (1 << COM1B1) | (1 << COM1A1);

  TCCR1B = (1 << CS11);

  TCCR1C = 0;
}

void moteurs::avancer(int vitesse) {
  PORTD |= (0 << 3);
  PORTD |= (0 << 2);
  ajustementPWM(vitesse, vitesse);
}

void moteurs::reculer(int vitesse) {
  PORTD |= (1 << 3);
  PORTD |= (1 << 2);
  ajustementPWM(vitesse, vitesse);
}

void moteurs::tournerDroite() {
  PORTD |= (1 << 3);
  PORTD |= (0 << 2);
  int rotationSpeed = 255;
  ajustementPWM(rotationSpeed, rotationSpeed);
  _delay_ms(500);
  arreterMoteurs();
}

void moteurs::tournerGauche() {
  PORTD |= (0 << 3);
  PORTD |= (1 << 2);
  int rotationSpeed = 255;
  ajustementPWM(rotationSpeed, rotationSpeed);
  _delay_ms(500);
  arreterMoteurs();
}

void moteurs::arreterMoteurs() {
  PORTD |= (0 << 3);
  PORTD |= (0 << 2);
  int zero = 0;
  ajustementPWM(zero, zero);
}

moteurs::moteurs() {
  // cli est une routine qui bloque toutes les interruptions.
  // Il serait bien mauvais d'être interrompu alors que
  // le microcontroleur n'est pas prêt...

  cli();

  // configurer et choisir les ports pour les entrées
  // et les sorties. DDRx... Initialisez bien vos variables

  DDR_PWM = MODE_SORTIE;

  // cette procédure ajuste le registre EIMSK
  // de l’ATmega324PA pour permettre les interruptions externes

  EIMSK |= (1 << INT0);

  // il faut sensibiliser les interruptions externes aux
  // changements de niveau du bouton-poussoir
  // en ajustant le registre EICRA

  EICRA |= (1 << ISC00);

  // sei permet de recevoir à nouveau des interruptions.

  sei();
}
