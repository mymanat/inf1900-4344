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
#include "memoire_24.h"

enum Couleurs {
    Eteint, Vert, Rouge
};


void transmissionUART(unsigned char donnee) {

    PORTB = Rouge;
    /* Wait for empty transmit buffer */
    while (!(UCSR0A & (1 << UDRE0)));
    /* Put data into buffer, sends the data */
    UDR0 = donnee;
    PORTB = Vert;

}

void initialisationUART(void) {

// 2400 bauds. Nous vous donnons la valeur des deux

// premier registres pour vous éviter des complications

    UBRR0H = 0;

    UBRR0L = 0xCF;

// permettre la reception et la transmission par le UART0

    UCSR0A;

    UCSR0B = (1 << RXEN0) | (1 << TXEN0);

// Format des trames: 8 bits, 1 stop bits, none parity

    UCSR0C;

}


int main() {

    DDRB = MODE_SORTIE;

    PORTB = Rouge;
    Memoire24CXXX memoire24CXXX;

    initialisationUART();


    uint8_t donnee;
    uint16_t i = 0x00;
    for (; donnee != 0xFF; ++i) {
        memoire24CXXX.lecture(i, &donnee);

        transmissionUART(donnee);

    }



    return 0;
}