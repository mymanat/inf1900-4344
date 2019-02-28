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

enum State { Init, S1, S2, S3, S4, S5 };
enum Couleurs { Eteint, Vert, Rouge };

volatile uint8_t minuterieExpiree;
volatile uint8_t boutonPoussoir;

const int DUREE_1S = 7812;

ISR(TIMER1_COMPA_vect) { minuterieExpiree = 1; }

ISR(INT0_vect) {
  boutonPoussoir = 1;
  _delay_ms(30);
}

void partirMinuterie(uint16_t duree) {
  minuterieExpiree = 0;

  // mode CTC du timer 1 avec horloge divisée par 1024
  // interruption après la durée spécifiée

  TCNT1 = 0;

  OCR1A = duree;

  TCCR1A = (1 << WGM12);

  TCCR1B = (1 << CS12) | (1 << CS10);

  TCCR1C = 0;

  TIMSK1 = (1 << OCIE1A);
}

void initialisation(void) {
  // cli est une routine qui bloque toutes les interruptions.
  // Il serait bien mauvais d'être interrompu alors que
  // le microcontroleur n'est pas prêt...

  cli();

  // configurer et choisir les ports pour les entrées
  // et les sorties. DDRx... Initialisez bien vos variables

  DDRB = MODE_SORTIE;

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

int main() {
  initialisation();

  _delay_ms(10000);
  PORTB = Rouge;
  _delay_ms(100);
  PORTB = Eteint;

  boutonPoussoir = 0;
  partirMinuterie(DUREE_1S);

  do {
    // attendre qu'une des deux variables soit modifiée
    // par une ou l'autre des interruptions.
  } while (minuterieExpiree == 0 && boutonPoussoir == 0);

  // Une interruption s'est produite. Arrêter toute
  // forme d'interruption. Une seule réponse suffit.

  cli();

  // Verifier la réponse

  if (minuterieExpiree == 1) {
    PORTB = Rouge;
  }
  if (boutonPoussoir == 1) {
    PORTB = Vert;
  }
  return 0;
}