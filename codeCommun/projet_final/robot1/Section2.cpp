//
// Created by simon on 4/9/19.
//

#include "Section2.h"

Section2::Section2() {
    setShouldGoStraight(false);
}

void Section2::evaluateCurve(uint8_t code) {
    if (compareBits(code, "00xx1")) {
        hitCount += 5;
    }
    else if (compareBits(code, "00x1x")) {
        hitCount++;
    }
    else if (compareBits(code, "1xx00")) {
        hitCount -= 5;
    }
    else if (compareBits(code, "x1x00")) {
        hitCount --;
    }

    if (hitCount <= 10) {
        hitCount = 10;
    }


}

bool Section2::evaluateState(uint8_t code) {
    evaluateCurve(code);

    int16_t a = 800;

    uint8_t time1a = hitCount >> 8;
    uint8_t time1b = hitCount & 0xff;

    transmissionUART(time1a);
    transmissionUART(time1b);
    transmissionUART(0xff);


    switch (state)
    {

        case 0:
//            if (hitCount > a) {
//                setSpeed(MOTOR_SLOW_SPEED);
//                motor.stop();
//                wait(100);
//                changeStateSound();
//                state = 1;
//            }
        case 1:

            if (compareBits(code, "11100")) {

                changeStateSound();
                changeStateSound();
                changeStateSound();
                setSpeed(MOTOR_SLOW_SPEED);

                state++;
            }


            break;
        case 2:
            if (compareBits(code, "00100")) {
                changeStateSound();
                changeStateSound();

                setSpeed(MOTOR_MAX_SPEED);
                state++;
            }
            break;
    }


    return true;//todo
}

void Section2::evaluateAction(uint8_t code) {



    uint8_t speed1 = 150;
    uint8_t speed2 = speed1 / 2;



    switch (state) {
        case 2:
            motor.adjust(MOTOR_MAX_SPEED, 0);
            break;
        default:
            followLine(code);
            break;
    }


}


