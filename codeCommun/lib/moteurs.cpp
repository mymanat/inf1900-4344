#include "moteurs.h"

void ajustementPWM(int pa, int pb) {
  // mise à un des sorties OC1A et OC1B sur comparaison

  // réussie en mode PWM 8 bits, phase correcte

  // et valeur de TOP fixe à 0xFF (mode #1 de la table 17-6

  // page 177 de la description technique du ATmega324PA)

  OCR1A = 255 * ((float)pa / 100);

  OCR1B = 255 * ((float)pb / 100);

  // division d'horloge par 8 - implique une frequence de PWM fixe

  TCCR1A = (1 << WGM10) | (1 << COM1B1) | (1 << COM1A1);

  TCCR1B = (1 << CS11);

  TCCR1C = 0;
}