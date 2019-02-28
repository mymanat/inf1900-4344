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

    /* Wait for empty transmit buffer */
    while (!(UCSR0A & (1 << UDRE0)));
    /* Put data into buffer, sends the data */
    UDR0 = donnee;

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

void log(char mots[]) {
    for (char i = 0, character = mots[i]; character != '\0' && i < 100; i++, character = mots[i]) {
        transmissionUART(character);
    }
}

int main() {

    DDRB = MODE_SORTIE;

    PORTB = Rouge;

    initialisationUART();

//    char message[30];
//    sprintf(message, "%d [a] %d, %d, %X, %d\n", a, b, PINA, lecan.lecture(0), data);
//    log(message);

    char mots[] = "Le robot en INF1900\n";


    log(mots);


    return 0;
}