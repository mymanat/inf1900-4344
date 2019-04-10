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
 * Exemple: value=0b10011
 * compareString="100xx"
 * Retourne vrai
 *
 * @param value
 * @param compareString Chaine de 1,0, ou x (don't care)
 */
bool compareBits(uint8_t value, char *compareString) {
    for (uint8_t i = 0; compareString[i] != '\0'; i++)
    {
        bool a = 1 & (value >> i);
        if (!(compareString[i] == 'x' || a == compareString[i]))
        {
            return false;
        }

    }

    return true;
}
