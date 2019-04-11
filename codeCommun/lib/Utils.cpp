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
