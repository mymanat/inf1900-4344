//
// Created by simon on 4/9/19.
//

#include "Section2.h"

Section2::Section2() {

}

void Section2::evaluateCurve(uint8_t code) {
    if (compareBits(code, "00100"))
    {
        hitCount += (hitCount < hitCountHalf) ? 1 : -1;
    }
    else if (compareBits(code, "00xxx"))
    {

        if (hitCount < hitCountHalf)
        {
            hitCount = hitCountHalf;
        }

        hitCount += SECTION2_DECEL_FACTOR *
                    (compareBits(code, "00xx1") ? SECTION2_HARD_TURN_SPEED_FACTOR : 1);
    }
    else
    {
        if (hitCount > hitCountHalf)
        {
            hitCount = hitCountHalf;
        }

        hitCount -= SECTION2_DECEL_FACTOR *
                    (compareBits(code, "1xx00") ? SECTION2_HARD_TURN_SPEED_FACTOR : 1);
    }

    /*
     * On borne le hitCount entre [SECTION2_DECEL_FACTOR ; hitCountMax]
     */
    if (hitCount <= SECTION2_DECEL_FACTOR)
    {
        hitCount = SECTION2_DECEL_FACTOR;
    }
    else if (hitCount >= hitCountMax)
    {
        hitCount = hitCountMax;
    }


}

bool Section2::evaluateState(uint8_t code) {
    evaluateCurve(code);


    uint8_t speed = a * pow(hitCount - hitCountHalf, 2) + max;


    switch (state)
    {

        case 0:
            if (compareBits(code, "11100"))
            {
                motor.stop();
                changeStateSound();
                wait(TRANSITION_DELAY_1);
                motor.adjust(getSpeed(), 0);

                state++;
            }


            break;
        case 1:
            if (compareBits(code, "00100"))
            {
                motor.stop();
                changeStateSound();
                wait(TRANSITION_DELAY_1);

                hitCount = hitCountHalf;
                state++;
            }
            break;
        case 2:
            if (compareBits(code, "00111"))
            {
                motor.stop();
                motor.adjust(0, MOTOR_MAX_SPEED);
                changeStateSound();
                return false;

            }
            break;
    }

    setSpeed(speed);

    return true;
}

void Section2::evaluateAction(uint8_t code) {
    followLine(code);

}


