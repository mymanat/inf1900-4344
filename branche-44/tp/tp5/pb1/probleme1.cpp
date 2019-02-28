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

#define MODE_SORTIE 0xff
#define MODE_ENTREE 0x00

#define DELAY_1_BYTE 5

#include <util/delay.h>
#include "memoire_24.h"

enum Couleurs {
    Eteint, Vert, Rouge
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

    DDRB = MODE_SORTIE;

    PORTB = Rouge;


    Memoire24CXXX memoire24CXXX;



    uint8_t donnes[] = " *P*O*L*Y*T*E*C*H*N*I*Q*U*E* *M*O*N*T*R*E*A*L*";
    uint8_t longueur = sizeof(donnes);

    uint16_t adresse = 0x00;

    memoire24CXXX.ecriture(adresse, donnes, longueur);


    wait(DELAY_1_BYTE * longueur);
    uint8_t word[longueur];
    memoire24CXXX.lecture(adresse, word, longueur);

    PORTB = Vert;

    for (int i = 0; i < longueur; i++) {

        if (word[i] != donnes[i]) {
            PORTB = Rouge;
            break;
        }
    }



    return 0;
}