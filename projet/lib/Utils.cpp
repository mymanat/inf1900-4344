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

uint8_t invertBitsPos(uint8_t value, uint8_t length) {
    uint8_t invertedValue = 0;
    uint8_t j = 0;
    for (uint8_t i = 0; i < length; ++i)
    {

        j = length - i - 1;
        invertedValue |= ((value >> j) & 1) << i;

    }

    return invertedValue;

}


void wait(double __ms) {
    double __tmp;

    uint16_t __ticks;
    __tmp = ((F_CPU) / 4e3) * __ms;
    if (__tmp < 1.0)
    {
        __ticks = 1;
    }
    else if (__tmp > 65535)
    {
        //  __ticks = requested delay in 1/10 ms
        __ticks = (uint16_t) (__ms * 10.0);
        while (__ticks)
        {
            // wait 1/10 ms
            _delay_loop_2(((F_CPU) / 4e3) / 10);
            __ticks--;
        }
        return;
    }
    else
    {
        __ticks = (uint16_t) __tmp;
    }
    _delay_loop_2(__ticks);
}
