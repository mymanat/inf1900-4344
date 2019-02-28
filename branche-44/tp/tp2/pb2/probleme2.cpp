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


#define F_CPU    8000000
#define DELAY 10
#define PRESSED 0x04

#include <util/delay.h>


enum State {
    Init, S1, S2, S3, S4, S5
};
enum Couleurs {
    Eteint, Vert, Rouge, Ambre
};

void incrementState(uint8_t & state){
    state++;
    if (state > S5) {
        state = Init;
    }
}

int main() {
    DDRB = 0xff; // PORT B est en mode sortie
    DDRD = 0x00;


    uint8_t state = Init;
    bool pressed = false;
    for (;;) {

        /* On verifie si l'etat du bouton a change */
        pressed = PIND & PRESSED;
        if (pressed) {
            _delay_ms(DELAY);
        }
        switch (state) {
            case Init:
                PORTB = Rouge;
                if (pressed) {
                    incrementState(state);
                }
                break;
            case S1:
                PORTB = Eteint;
                _delay_ms(DELAY);
                PORTB = Rouge;
                if (!pressed) {
                    incrementState(state);
                }
                break;
            case S2:
                PORTB = Vert;
                if (pressed) {
                    incrementState(state);
                }
                break;
            case S3:
                PORTB = Rouge;
                if (!pressed) {
                    incrementState(state);
                }
                break;
            case S4:
                PORTB = Eteint;
                if (pressed) {
                    incrementState(state);
                }
                break;
            case S5:
                PORTB = Vert;
                if (!pressed) {
                    incrementState(state);
                }
                break;
        }
    }
    return 0;
}

