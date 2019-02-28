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
#include "can.h"

#define F_CPU 8000000
// PRESSED_MINIMUM vaut 128. Puisque signal analogique vaut soit 255 ou 0,
// confirmer si la valeur analogique est plus petite que 128 est un moyen
// d'éviter toute interférence.
#define PRESSED_MINIMUM 0x80

#define MODE_SORTIE 0xff;
#define MODE_ENTREE 0x00;

#include <util/delay.h>

enum Etats { E0, E1, E2, E3, E4, E5, E6 };
enum Couleurs { Eteint, Vert, Rouge };

volatile uint8_t minuterieExpiree;
volatile uint8_t compteur;

volatile int etat;

const int DUREE_1S = 7812;

ISR(TIMER1_COMPA_vect) {
  ++compteur;
  if (compteur >= 120) {
    minuterieExpiree = 1;
  }
}

void partirCompteur() {
  minuterieExpiree = 0;
  compteur = 0;

  TCNT1 = 0;

  OCR1A = (int)(DUREE_1S / 10.0);

  TCCR1A = 0;

  TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10);

  TCCR1C = 0;

  TIMSK1 = (1 << OCIE1A);
}

void initialisation() {
  cli();

  etat = E0;

  DDRB = MODE_ENTREE;
  DDRC = MODE_SORTIE;

  sei();
}

int main() {
  initialisation();

  can convertisseur;
  uint16_t valeurBouton;

  while (true) {
    switch (etat) {
      case E0:
        do {
          valeurBouton = convertisseur.lecture(0) >> 2;
        } while (valeurBouton >= PRESSED_MINIMUM);
        ++etat;
        break;

      case E1:
        partirCompteur();
        do {
          valeurBouton = convertisseur.lecture(0) >> 2;
        } while (valeurBouton <= PRESSED_MINIMUM && minuterieExpiree == 0);
        ++etat;
        break;

      case E2:
        PORTC = Vert;
        _delay_ms(500);
        PORTC = Eteint;
        ++etat;
        break;

      case E3:
        _delay_ms(2000);
        ++etat;
        break;

      case E4:
        for (int tempsS = 0; tempsS < 4; ++tempsS) {
          PORTC = Rouge;
          _delay_ms(250);
          PORTC = Eteint;
          _delay_ms(250);
          PORTC = Rouge;
          _delay_ms(250);
          PORTC = Eteint;
          _delay_ms(250);
        }
        ++etat;
        break;

      case E5:
        PORTC = Vert;
        _delay_ms(1000);
        PORTC = Eteint;
        ++etat;
        break;

      case E6:
        _delay_ms(1000);
        etat = E0;
        break;
    }
  }

  return 0;
}