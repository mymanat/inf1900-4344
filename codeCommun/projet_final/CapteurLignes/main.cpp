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
    int cste = 500;
    DDRA = MODE_ENTREE;
    DDRC = MODE_SORTIE;
    //DDRB = MODE_ENTREE;
    DDRD = MODE_SORTIE;

    can convertisseur;
    int valeurNoir = convertisseur.lecture(3);

    uint16_t valeurLue;
    char str[16];

    initialisationUART();

    PORTC = 0xff;

    while (1)
    {
        valeurLue = convertisseur.lecture(0);
        itoa(valeurLue, str, 10);

        log_uart(str);
        log_uart("\n");

        if (valeurLue > valeurNoir + cste)
        {
            setBit(&PORTC, 0, POSITION_DEL_1);
        }
        else
        {
            setBit(&PORTC, 1, POSITION_DEL_1);
        }

        valeurLue = convertisseur.lecture(1);

        if (valeurLue > valeurNoir + cste)
        {
            setBit(&PORTC, 0, POSITION_DEL_2);
        }
        else
        {
            setBit(&PORTC, 1, POSITION_DEL_2);
        }

        valeurLue = convertisseur.lecture(2);

        if (valeurLue > valeurNoir + cste)
        {
            setBit(&PORTC, 0, POSITION_DEL_3);
        }
        else
        {
            setBit(&PORTC, 1, POSITION_DEL_3);
        }

        valeurLue = convertisseur.lecture(3);

        if (valeurLue > valeurNoir + cste)
        {
            setBit(&PORTC, 0, POSITION_DEL_4);
        }
        else
        {
            setBit(&PORTC, 1, POSITION_DEL_4);
        }

        valeurLue = convertisseur.lecture(4);

        if (valeurLue > valeurNoir + cste)
        {
            setBit(&PORTC, 0, POSITION_DEL_5);
        }
        else
        {
            setBit(&PORTC, 1, POSITION_DEL_5);
        }
    }
}
