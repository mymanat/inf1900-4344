#include <avr/io.h>
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

    while (1)
    {
        irSensor = convertisseur.lecture(6);
        if(irSensor > 900){
            setBit(&PORTC, 1, POSITION_DEL_5);
        }
        else{
            setBit(&PORTC, 0, POSITION_DEL_5);
        }

    }
}
