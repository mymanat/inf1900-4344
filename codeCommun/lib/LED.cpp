//
// Created by simon on 3/18/19.
//

#include "LED.h"


void LED::turnOn(uint8_t numLED) const {
    setState(true, numLED);
}

void LED::turnOn() const {
    setState(true);
}

void LED::turnOff(uint8_t numLED) const {
    setState(false, numLED);
}

void LED::turnOff() const {
    setState(false);
}

void LED::setState(bool state, uint8_t numLED) const {
    if (numLED == 0)
    {
        return;
    }
    if (state)
    {
        setBit(&PORT_LED, true, getLEDPosition(numLED));
    }
    else
    {
        setBit(&PORT_LED, false, getLEDPosition(numLED));
    }


}

void LED::setState(bool state) const {
    for (uint8_t i = 1; i <= LED_COUNT; ++i)
    {
        setState(state, i);
    }
}

uint8_t LED::getLEDPosition(uint8_t numLED) const {
    switch (numLED)
    {
        case 1:
            return POSITION_LED_1;
            break;
        case 2:
            return POSITION_LED_2;
            break;
        case 3:
            return POSITION_LED_3;
            break;
        case 4:
            return POSITION_LED_4;
            break;
        case 5:
            return POSITION_LED_5;
            break;
        default:
            DEBUG_PRINT("ERREUR: Mauvais numero de DEL");
            return 0;
            break;
    }
}


LED::LED() {
    DDR_LED = MODE_OUTPUT;
}


