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
 *
 */


#include <avr/io.h>

#define F_CPU 8000000

#include <util/delay.h>

enum Couleurs {
    Eteint = 0b000000,
    Vert = 0b01010101, //Permet d'obtenir la couleur désirée peut importe la pin sur laquelle la led est branchée
    Rouge = 0b10101010
};


/*
 * Fonction prise du code source de _delay_ms(double __ms) et adaptée pour accepter les paramètres variables
 * https://www.nongnu.org/avr-libc/user-manual/delay_8h_source.html
 * https://github.com/omnidan/ArduinoPure/blob/master/tools/avr/lib/avr/include/util/delay.h
 *
 */
void wait(double __ms) {
    uint16_t __ticks;
    double __tmp = ((F_CPU) / 4e3) * __ms;
    if (__tmp < 1.0)
        __ticks = 1;
    else if (__tmp > 65535) {
        //	__ticks = requested delay in 1/10 ms
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
    DDRA = 0xff; // PORT B est en mode sortie
    DDRC = 0xff;
    DDRD = 0x00; // PORT D est en mode entree

    double f = 60e-3;//Hz
    double b = 1 / f;//1000/60;//1.0 / f;// * 1000;//ms
    double a = 0;
    double c = 0;

    double tempsDepuisDebut = 0; // En micro secondes.
    double tempsTotal = 20e3;     // 3 secondes en micro secondes.


    double stateTime = 0;
    int state = 0;
    int i = 0, k = 0;
    PORTA = Vert;
    while (tempsDepuisDebut < tempsTotal && state <= 10) {
        if (stateTime > 2e3) {
            switch (i) {
                case 0:
                    PORTA = Eteint;
                    i++;
                    break;
                case 1://0.5
                    PORTA = Rouge;
                    i++;
                    break;
                case 2://0.75
                    PORTA = Vert;
                    i++;
                    break;
                case 3://100
                    PORTA = Rouge;
                    i = 0;
                    break;

            }
            if (k == 1) {
                f = 400e-3;
                b = 1 / f;
            }

            stateTime = 0;
            c += 0.25;
            if (c > 1) {
                c = 0;
                k = 1;
            }

        }
        a = c * b;

        PORTB = Rouge;
        PORTC = Rouge;
        wait(a);
        PORTB = Eteint;
        PORTC = Eteint;
        wait(b - a);

        tempsDepuisDebut += b;
        stateTime += b;
    }
    PORTB = Eteint;

    return 0;
}
