#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

#include "Utils.h"
#include "memoire_24.h"
#include "constantes.h"
#include "wait.h"
#include "LOG.h"
#include "can.h"

#include "DEL.h"

int main()
{
    uint16_t cste = 500;
    DDRA = MODE_ENTREE;
//    DDRB = MODE_ENTREE;
//    DDRC = MODE_SORTIE;
//    DDRD = MODE_SORTIE;

    DEL del;

    can convertisseur;
    uint16_t  valeurNoir = convertisseur.lecture(3);

    uint16_t valeurLue;
    char str[16];

    initialisationUART();

//    PORTC = 0xff;


    while (1)
    {
        valeurLue = convertisseur.lecture(0);
        itoa(valeurLue, str, 10);

        log_uart(str);
        log_uart("\n");

        if (valeurLue > valeurNoir + cste)
        {
            del.eteindre(1);
//            setBit(&PORTC, 0, POSITION_DEL_1);
        }
        else
        {
            del.allumer(1);
//            setBit(&PORTC, 1, POSITION_DEL_1);
        }

        valeurLue = convertisseur.lecture(1);

        if (valeurLue > valeurNoir + cste)
        {
            del.eteindre(2);
        }
        else
        {
            del.allumer(2);
        }

        valeurLue = convertisseur.lecture(2);

        if (valeurLue > valeurNoir + cste)
        {
            del.eteindre(3);
        }
        else
        {
            del.allumer(3);
        }

        valeurLue = convertisseur.lecture(3);

        if (valeurLue > valeurNoir + cste)
        {
            del.eteindre(4);
        }
        else
        {
            del.allumer(4);
        }

        valeurLue = convertisseur.lecture(4);

        if (valeurLue > valeurNoir + cste)
        {
            del.eteindre(5);
        }
        else
        {
            del.allumer(5);
        }
    }
}
