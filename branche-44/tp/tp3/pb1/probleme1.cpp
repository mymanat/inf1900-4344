/*
 * Nom: compteur 32 bits
 * Copyright (C) 2005 Matthew Khouzam
 * License http://www.gnu.org/copyleft/gpl.html GNU/GPL
 * Description: Ceci est un exemple simple de programme
 * Version: 1.1
 */



/*
 * Simon Tran 1961278
 * Samuel Poulin 1960424
 * Groupe 3
 *
 */


#include <avr/io.h>

#define F_CPU 8000000

#include <util/delay.h>

enum Couleurs {
    Eteint,
    Vert,
    Rouge
};


/*
 * Fonction prise du code source de _delay_ms(double __ms) et adaptée pour accepter les paramètres variables
 * https://www.nongnu.org/avr-libc/user-manual/delay_8h_source.html
 *
 */

void wait(double __ms) {
    double __tmp;

    uint16_t __ticks;
    __tmp = ((F_CPU) / 4e3) * __ms;
    if (__tmp < 1.0)
        __ticks = 1;
    else if (__tmp > 65535) {
        //  __ticks = requested delay in 1/10 ms
        __ticks = (uint16_t)(__ms * 10.0);
        while (__ticks) {
            // wait 1/10 ms
            _delay_loop_2(((F_CPU) / 4e3) / 10);
            __ticks--;
        }
        return;
    } else
        __ticks = (uint16_t) __tmp;
    _delay_loop_2(__ticks);
}

int main() {
    DDRB = 0xff; // PORT B est en mode sortie
    DDRD = 0x00; // PORT D est en mode entree

    double b = 1; // En micro secondes, donc 1/1000 secondes
    double a = 1;

    double tempsDepuisDebut = 0; // En micro secondes.
    double tempsTotal = 3e3;     // 3 secondes en micro secondes.

    double ratio = -b / tempsTotal;
    while (tempsDepuisDebut < tempsTotal) {
        a = tempsDepuisDebut * ratio + b;

        PORTB = Rouge;
        wait(a);
        PORTB = Eteint;
        wait(b - a);

        tempsDepuisDebut += b;
    }
    PORTB = Eteint;

    return 0;
}
