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

#include <avr/io.h>
#include <util/delay.h>
#include "can.h"

#define F_CPU 8000000

#define MODE_SORTIE 0xff
#define MODE_ENTREE 0x00
#define DELAIS 10

/* La valeur qui différencie les différents niveaux de luminosités */
#define DELTA_LUMIERE 10


enum Couleurs {
    Eteint, Vert, Rouge
};


int main() {
    DDRB = MODE_SORTIE;
    DDRA = MODE_ENTREE;

    can lecan;

    uint16_t ambiant = lecan.lecture(0) >> 2;/* on ignore les 2 bits les moins significatifs */

    bool ambre = false;
    uint16_t lumiere;
    while (true) {
        _delay_ms(DELAIS);

        lumiere = lecan.lecture(0) >> 2;

        if (lumiere > ambiant + DELTA_LUMIERE) {
            PORTB = Rouge;
        }
        else if (lumiere < ambiant - DELTA_LUMIERE) {
            PORTB = Vert;
        }
        else {
            PORTB = ambre ? Eteint : Rouge;
            ambre = !ambre;
        }



    }

}