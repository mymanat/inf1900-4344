#include "Utils.h"

void setBit(volatile uint8_t *variable, bool valeur, uint8_t bitIndex) {
    if (valeur)
    {
        *variable |= (1 << bitIndex);
    }
    else
    {
        *variable &= ~(1 << bitIndex);
    }
}

void setBit(uint8_t *variable, bool valeur, uint8_t bitIndex) {
    setBit((volatile uint8_t *) variable, valeur, bitIndex);
}


/**
 * Test si les bits du monde match la compareString
 * La valeur 'x' correspond à un "don't care" (ok pour 1 ou 0)
 * La fonction retourne vrai si la valeur contient au moins un '0' là où il y a le charactère 'y' dans la compareString
 * La fonction retourne vrai si la valeur contient au moins un '1' là où il y a le charactère 'y' dans la compareString
 *
 * La chaine doit etre de longueur 5
 * Exemple: value=0b10011
 * compareString="100xx"
 * Retourne vrai
 *
 * value=0b11111
 * compareString="101xy"
 * Retourne faux, car au moins un 'y' n'a pas de '0' correspondant
 *
 * value=0b10101
 * compareString="zzxxx"
 * retourne vrai, car au moins un 'z' a un '1'
 *
 */
bool compareBits(uint8_t value, const char *compareString) {

    bool hasACorrectYValue = false;
    bool hasACorrectZValue = false;
    bool hasNoYorZ = true;
    for (uint8_t i = 0; compareString[i] != '\0'; ++i)
    {

        bool a = 1 & (value >> (4 - i));
        if (compareString[i] == 'y')
        {
            hasNoYorZ = false;
            if (!a)
            {
                hasACorrectYValue = true;
            }
        }
        else if (compareString[i] == 'z')
        {
            hasNoYorZ = false;
            if (a)
            {
                hasACorrectZValue = true;
            }

        }
        else if (compareString[i] != 'x' && a != compareString[i] - 48)
        {
            return false;
        }

    }

    return hasNoYorZ || hasACorrectYValue || hasACorrectZValue;
}
