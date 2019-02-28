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


/*
 *
╔══════════════╦═════════════════╦══════════════╦═════════╗
║ État Present ║ Button Appuyé?  ║ État Suivant ║ Sortie  ║
╠══════════════╬═════════════════╬══════════════╬═════════╣
║ Init         ║ NON             ║ Init         ║  Rouge  ║
╠══════════════╬═════════════════╬══════════════╬═════════╣
║ Init         ║ OUI             ║ S1           ║ Rouge   ║
╠══════════════╬═════════════════╬══════════════╬═════════╣
║ S1           ║ NON             ║ S2           ║ Ambré   ║
╠══════════════╬═════════════════╬══════════════╬═════════╣
║ S1           ║ OUI             ║ S1           ║ Ambré   ║
╠══════════════╬═════════════════╬══════════════╬═════════╣
║ S2           ║ NON             ║ S2           ║ VERT    ║
╠══════════════╬═════════════════╬══════════════╬═════════╣
║ S2           ║ OUI             ║ S3           ║ VERT    ║
╠══════════════╬═════════════════╬══════════════╬═════════╣
║ S3           ║ NON             ║ S4           ║ ROUGE   ║
╠══════════════╬═════════════════╬══════════════╬═════════╣
║ S3           ║ OUI             ║ S3           ║ ROUGE   ║
╠══════════════╬═════════════════╬══════════════╬═════════╣
║ S4           ║ NON             ║ S4           ║ Éteinte ║
╠══════════════╬═════════════════╬══════════════╬═════════╣
║ S4           ║ OUI             ║ S5           ║ Éteinte ║
╠══════════════╬═════════════════╬══════════════╬═════════╣
║ S5           ║ NON             ║ Init         ║ VERT    ║
╠══════════════╬═════════════════╬══════════════╬═════════╣
║ S5           ║ OUI             ║ S5           ║ VERT    ║
╚══════════════╩═════════════════╩══════════════╩═════════╝
 *
 */


#include <avr/io.h>
#include <avr/interrupt.h>


#define F_CPU    8000000
#define DELAY 10
#define PRESSED 0x04

#define MODE_SORTIE 0xff;
#define MODE_ENTREE 0x00;

#include <util/delay.h>


enum State {
    Init, S1, S2, S3, S4, S5
};
enum Couleurs {
    Eteint, Vert, Rouge, Ambre
};


volatile uint8_t state = Init;

void incrementState() {
    state++;
    if (state > S5) {
        state = Init;
    }

}

ISR(INT0_vect) {

// laisser un delai avant de confirmer la réponse du

// bouton-poussoir: environ 30 ms (anti-rebond)

        _delay_ms(30);

// se souvenir ici si le bouton est pressé ou relâché

        bool pressed = PIND & PRESSED;

// changements d'états tels que ceux de la

// semaine précédente


        switch (state){
            case Init:
            case S2:
            case S4:
                if (pressed) {
                    incrementState();
                }
            break;

            case S1:
            case S3:
            case S5:
                if (!pressed) {
                    incrementState();
                }
            break;
        }

// Voir la note plus bas pour comprendre cette instruction et son rôle

        EIFR |= (1 << INTF0);

}


void initialisation(void) {

// cli est une routine qui bloque toutes les interruptions.

// Il serait bien mauvais d'être interrompu alors que

// le microcontroleur n'est pas prêt...

    cli();


// configurer et choisir les ports pour les entrées

// et les sorties. DDRx... Initialisez bien vos variables

    DDRB = MODE_SORTIE;
    DDRD = MODE_ENTREE;
    state = Init;


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

    for (;;) {


        switch (state) {
            case Init:
                PORTB = Rouge;
                break;
            case S1:
                _delay_ms(DELAY);
                PORTB = Eteint;
                _delay_ms(DELAY);
                PORTB = Rouge;
                break;
            case S2:
                PORTB = Vert;
                break;
            case S3:
                PORTB = Rouge;
                break;
            case S4:
                PORTB = Eteint;
                break;
            case S5:
                PORTB = Vert;
                break;
        }
    }
    return 0;
}

