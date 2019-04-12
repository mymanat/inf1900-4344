//
// Created by simon on 4/9/19.
//

#include "Section3.h"

Section3::Section3() {
    setSpeed(MOTOR_SLOW_SPEED);

}


bool Section3::followLineSection3(uint8_t code) {
    return followLine(code);

}

bool Section3::evaluateState(uint8_t code) {
    if (state > 3 && state < 8)
    {
        loopCounter++;
    }
    switch (state)
    {
        case 0:
            if (compareBits(code, "11111"))
            {
                motor.stop();
                button.init();
                state++;

            }
            break;
        case 1:
            if (button.getState())
            {
                motor.init();
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
            if (compareBits(code, "0y1y0"))
            {
                state++;
            }
            break;
        case 4:
        case 6:
            checkLineDetection(code);
            break;
        case 5:
            if (compareBits(code, "0x1x0"))
            {
                state++;
            }
            break;
        case 7:
            if (compareBits(code, "00000"))
            {
#ifdef DEBUG
                uint8_t time1a = timeFirstLine >> 8;
                uint8_t time1b = timeFirstLine & 0xff;
                uint8_t time2a = timeSecondLine >> 8;
                uint8_t time2b = timeSecondLine & 0xff;

                transmissionUART(time1a);
                transmissionUART(time1b);
                transmissionUART(0xff);
                transmissionUART(time2a);
                transmissionUART(time2b);
#endif
                motor.stop();
                trackerSensor.setShouldUpdateDel(false);

                evaluateLine();
                button.init();
                state++;
            }
            break;
        case 8:
            if (button.getState())
            {
                trackerSensor.setShouldUpdateDel(true);
                motor.init();
                return false;
            }
            break;

    }
    return true;
}

void Section3::checkLineDetection(uint8_t code) {
    if (compareBits(code, "0xxx0"))
    {
        return;

    }
    if (timeFirstLine == 0)
    {
        timeFirstLine = loopCounter;

        leftFirst = compareBits(code, "00xx1");
    }

    else
    {
        timeSecondLine = loopCounter;
    }


    state++;

}

void Section3::evaluateLine() {
    led.turnOff();
    uint8_t id = 0;

//    if (loopCounter > DELTA_COUNTER)
    if (timeSecondLine - timeFirstLine > timeFirstLine * 2)
    {

        /* D1 ou D3 */
        id = leftFirst ? 1 : 3;
    }
    else
    {
        /* D2 ou D4 */
        id = leftFirst ? 2 : 4;
    }

    led.turnOn(id);
}

void Section3::evaluateAction(uint8_t code) {

    if (state != 8)
    {
        followLineSection3(code);

    }

}


