//
// Created by simon on 4/9/19.
//

#include "Section2.h"

Section2::Section2() {
    setShouldGoStraight(false);
//    double a = pow(-1 * (min - max), 1 / (hitCountMax / 2));


    a = (min - max) / pow(b, 2);

}

void Section2::evaluateCurve(uint8_t code) {
    uint8_t c = 15;
    if (compareBits(code, "00100"))
    {
        hitCount += (hitCount < b) ? 1 : -1;
    }
    else if (compareBits(code, "00xxx"))
    {

        if (hitCount < b)
        {
            hitCount = b;
        }

        if (compareBits(code, "00xx1"))
        {
            hitCount += 5 * c;
        }
        else if (compareBits(code, "00x1x"))
        {
            hitCount += 1 * c;
        }
    }
    else
    {
        if (hitCount > b)
        {
            hitCount = b;
        }
        if (compareBits(code, "1xx00"))
        {
            hitCount -= 5 * c;
        }
        else if (compareBits(code, "x1x00"))
        {
            hitCount -= 1 * c;
        }
    }

    if (hitCount <= c)
    {
        hitCount = c;
    }
    else if (hitCount >= hitCountMax)
    {
        hitCount = hitCountMax;
    }


}

bool Section2::evaluateState(uint8_t code) {
    evaluateCurve(code);


//    uint8_t time1a = hitCount >> 8;
//    uint8_t time1b = hitCount & 0xff;

//    transmissionUART(time1a);
//    transmissionUART(time1b);
//    transmissionUART(0xff);

//    double speed = -1 * pow(1.008, hitCount - 500) + max;
//    a = (min - max) / pow(b, 2);

    double speed = a * pow(hitCount - b, 2) + max;
    uint8_t speed1 = speed;

//    transmissionUART(
//            speed1
//    );


    switch (state)
    {

        case 0:
            if (compareBits(code, "11100"))
            {
                setSpeed(MOTOR_SLOW_SPEED);
                motor.stop();
                changeStateSound();
                wait(100);
                motor.adjust(getSpeed(), 0);

                state++;
            }


            break;
        case 1:
            if (compareBits(code, "00100"))
            {
                motor.stop();
                changeStateSound();
                wait(100);

                hitCount = b;
                state++;
            }
            break;
        case 2:
            if (compareBits(code, "00111")) {
                motor.stop();
                motor.adjust(0, MOTOR_MAX_SPEED);
                changeStateSound();
                return false;

            }
            break;
    }

    setSpeed(speed1);

    return true;//todo
}

void Section2::evaluateAction(uint8_t code) {


//    uint8_t speed1 = 150;
//    uint8_t speed2 = speed1 / 2;


    switch (state)
    {
//        case 1:
//            motor.adjust(MOTOR_MAX_SPEED, 0);
//            break;
        default:
            followLine(code);
            break;
    }


}


