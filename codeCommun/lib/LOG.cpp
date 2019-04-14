
#include "LOG.h"


void transmitUART(const uint8_t data) {

    /* Wait for empty transmit buffer */
    while (!(UCSR0A & (1 << UDRE0)));
    /* Put data into buffer, sends the data */
    UDR0 = data;

}
char receptUART() {
    /* Wait for empty transmit buffer */


    // Attend qu'il y ait des donnees de disponibles
    while (!(UCSR0A & (1 << RXC0)));

    /* Retourne les donnees*/
    return UDR0;
}


void initUART(void) {

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

void log_uart(const char words[]) {
    for (uint8_t i = 0; i < strlen(words); i++) {

        unsigned char character= words[i];
        transmitUART(character);
        if(character == '\0'){
            break;
        }
    }
}


