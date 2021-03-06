//
// Created by simon on 4/9/19.
//

#include "Section2.h"

Section2::Section2() {
    a = (SECTION2_MIN_SPEED - SECTION2_MAX_SPEED) / pow(hitCountHalf, 2);

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
    else if (hitCount >= SECTION2_HITCOUNT_MAX)
    {
        hitCount = SECTION2_HITCOUNT_MAX;
    }


}

bool Section2::evaluateState(uint8_t code) {
    evaluateCurve(code);


    uint8_t speed = a * pow(hitCount - hitCountHalf, 2) + SECTION2_MAX_SPEED;


    switch (state)
    {

        case 0:
            if (compareBits(code, "111x0"))
            {
                motor.stop();
                DEBUG_SOUND();
                wait(TRANSITION_DELAY_1);
                motor.adjust(getSpeed(), 0);

                state++;
            }


            break;
        case 1:
            if (compareBits(code, "00100"))
            {
                motor.stop();
                DEBUG_SOUND();
                wait(TRANSITION_DELAY_1);

                hitCount = hitCountHalf;
                state++;
            }
            break;
        case 2:
            if (compareBits(code, "00111"))
            {
                motor.stop();
                if (isShouldTurnAfterTransition())
                {

                    motor.adjust(0, MOTOR_FAST_SPEED);
                }
                DEBUG_SOUND();
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


