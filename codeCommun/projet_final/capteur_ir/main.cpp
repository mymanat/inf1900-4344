#include <avr/io.h>
#include <avr/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "memoire_24.h"
#include "constantes.h"
#include "wait.h"
#include "LOG.h"
#include "can.h"

int main()
{
    DDRA = MODE_ENTREE;
    DDRC = MODE_SORTIE;
    DDRB = MODE_ENTREE;
    DDRD = MODE_SORTIE;

    can convertisseur;


    uint16_t irSensor;

    PORTC = 0x00;

    uint16_t valeurLue;
    char str[16];
    initialisationUART();


    while (1)
    {
        irSensor = convertisseur.lecture(6);

        itoa(irSensor, str, 10);

        log_uart(str);
        log_uart("\n");

        if(irSensor < 100){
            setBit(&PORTC, 1, POSITION_DEL_5);
            _delay_ms(2000);
        }
        else{
            setBit(&PORTC, 0, POSITION_DEL_5);
        }

    }

}
