//
// Created by simon on 4/9/19.
//

#include "Section3.h"

Section3::Section3() {
    setVitesse(MOTOR_SLOW_SPEED);
}


bool Section3::followLineSection3(uint8_t code) {
    if (compareBits(code, "1xxxx") || compareBits(code, "xxxx1"))
    {
        moteur.goForward(getVitesse());
        return true;
    }
    return suivreLigne(code);

}

bool Section3::evaluateState(uint8_t code) {
    if (state > 3 && state < 6)
    {
        loopCounter++;
    }
    switch (state)
    {
        case 0:
            if (compareBits(code, "11111"))
            {
                moteur.stop();
                button.init();
                state++;

            }
            break;
        case 1:
            if (button.getState())
            {
                moteur.init();
                state++;
            }
            break;
        case 2:
            if (compareBits(code, "11111"))
            {
                state++;
            }
            break;
        case 3:
            if (compareBits(code, "00100"))
            {
                state++;
            }
            break;
        case 4:
            if (compareBits(code, "00111"))
            {
                leftFirst = true;
                state++;
            }
            else if (compareBits(code, "11100"))
            {
                leftFirst = false;
                state++;
            }
            break;
        case 5:
            if (compareBits(code, "00000"))
            {
#ifdef DEBUG
                uint8_t a = loopCounter >> 8;
            uint8_t b = loopCounter & 0xff;
            transmissionUART(a);
            transmissionUART(b);
#endif
                moteur.stop();
                trackerSensor.setShouldUpdateDel(false);

                evaluateLine();
                button.init();
                state++;
            }
            break;
        case 6:
            if (button.getState())
            {
                trackerSensor.setShouldUpdateDel(true);
                moteur.init();
                return false;
            }
            break;

    }
    return true;
}

void Section3::evaluateLine() {
    del.turnOff();
    uint8_t id = 0;

    if (loopCounter > DELTA_COUNTER)
    {
        /* D1 ou D3 */
        id = leftFirst ? 1 : 3;
    }
    else
    {
        /* D2 ou D4 */
        id = leftFirst ? 2 : 4;
    }

    del.turnOn(id);
}

void Section3::evaluateAction(uint8_t code) {

    if (state != 6)
    {
        followLineSection3(code);

    }

}


