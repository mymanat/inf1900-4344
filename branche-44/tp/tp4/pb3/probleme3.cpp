/*
 * Nom: compteur 32 bits
 * Copyright (C) 2005 Matthew Khouzam
 * License http://www.gnu.org/copyleft/gpl.html GNU/GPL
 * Description: Ceci est un exemple simple de programme
 * Version: 1.1
 */

/*
 *
 * Par
 * Samuel Poulin 1960424
 * Simon Tran 1961278
 * Groupe 03
 *
 */

#include <avr/interrupt.h>
#include <avr/io.h>

#define F_CPU 8000000
#define PRESSED 0x04

#define MODE_SORTIE 0xff;
#define MODE_ENTREE 0x00;

#include <util/delay.h>

enum State { Init, S1, S2, S3, S4 };
enum Couleurs { Eteint, Vert, Rouge };

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

void initialisation(void) {
  // cli est une routine qui bloque toutes les interruptions.
  // Il serait bien mauvais d'être interrompu alors que
  // le microcontroleur n'est pas prêt...

  cli();

  // configurer et choisir les ports pour les entrées
  // et les sorties. DDRx... Initialisez bien vos variables

  DDRD = MODE_SORTIE;

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

void changerPhases() {
  int etat = Init;

  while (true) {
    switch (etat) {
      case Init:
        ajustementPWM(0, 0);
        _delay_ms(2000);
        ++etat;
        break;
      case S1:
        ajustementPWM(25, 25);
        _delay_ms(2000);
        ++etat;
        break;
      case S2:
        ajustementPWM(50, 50);
        _delay_ms(2000);
        ++etat;
        break;
      case S3:
        ajustementPWM(75, 75);
        _delay_ms(2000);
        ++etat;
        break;
      case S4:
        ajustementPWM(100, 100);
        _delay_ms(2000);
        etat = Init;
        break;
    }
  }
}

int main() {
  initialisation();

  changerPhases();

  return 0;
}