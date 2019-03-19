#ifndef LOG_H
#define LOG_H
#include <avr/io.h>
#include "string.h"
#include <util/delay.h>



void transmissionUART(const char donnee) {

    /* Wait for empty transmit buffer */
    while (!(UCSR0A & (1 << UDRE0)));
    /* Put data into buffer, sends the data */
    UDR0 = donnee;

}
char receptionUART() {
    /* Wait for empty transmit buffer */


    // Attend qu'il y ait des donnees de disponibles
    while (!(UCSR0A & (1 << RXC0)));

    /* Retourne les donnees*/
    return UDR0;
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

void log_uart(const char mots[]) {
    for (uint8_t i = 0; i < strlen(mots); i++) {

        unsigned char character= mots[i];
        transmissionUART(character);
        if(character == '\0'){
            break;
        }
    }
}



#endif 
