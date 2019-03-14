#include <LOG.h>


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

void log_uart(char mots[]) {
    for (char i = 0, character = mots[i]; character != '\0' && i < 100; i++, character = mots[i]) {
        transmissionUART(character);
    }
}

