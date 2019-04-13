//
// Created by simon on 4/9/19.
//

#include "Section2.h"

Section2::Section2() {
    setShouldGoStraight(true);
}

bool Section2::evaluateState(uint8_t code) {

    switch (state)
    {

        case 0:
            if (hitCount > 1) {
                setSpeed(MOTOR_SLOW_SPEED);
                motor.stop();
                changeStateSound();
                state = 1;
            }
        case 1:

            if (hitCount <= 1)
            {
                setSpeed(MOTOR_MAX_SPEED);
                state = 0;
            }

            if (compareBits(code, "11100")) {

                setSpeed(MOTOR_SLOW_SPEED);

                state++;
            }


            break;
        case 2:
            if (compareBits(code, "00100")) {
                setSpeed(MOTOR_MAX_SPEED);
                hitCount = 0;
                state++;
            }
            break;
        case 3:
            if (hitCount > 1) {
                setSpeed(MOTOR_SLOW_SPEED);
                motor.stop();
                changeStateSound();
                state = 4;
            }
        case 4:
            if (hitCount <= 1)
            {
                setSpeed(MOTOR_MAX_SPEED);
                state = 0;
            }

            if (compareBits(code, "00111")) {

                return false;
            }


    }


    return true;//todo
}

void Section2::evaluateAction(uint8_t code) {

    switch (state)
    {
        case 0:
        case 1:
        case 3:
//            transmissionUART(hitCount);

            if (shouldIncrementHitCount && compareBits(code, "x1xxx"))
            {
                if (hitCount != 0) {
                    hitCount--;

                }
                shouldIncrementHitCount = false;
            }
            else if (shouldIncrementHitCount && compareBits(code, "xxx1x"))
            {
                hitCount++;
                shouldIncrementHitCount = false;
            }
            else if (compareBits(code, "00100"))
            {
                shouldIncrementHitCount = true;
            }

            break;
    }


    switch (state) {
        case 2:
            motor.adjust(MOTOR_MAX_SPEED, 0);
            break;
        default:
            followLine(code);
            break;
    }


}


