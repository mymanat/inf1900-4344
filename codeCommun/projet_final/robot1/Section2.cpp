//
// Created by simon on 4/9/19.
//

#include "Section2.h"

Section2::Section2() {
    setShouldGoStraight(false);
}

bool Section2::evaluateState(uint8_t code) {
//    transmissionUART(hitCount);

    switch (state)
    {

        case 0:
            if (compareBits(code, "xxxx1"))
            {
                state++;
            }
//               if (hitCount > 1)
//               {
////                   setSpeed(MOTOR_SLOW_SPEED);
//   //                motor.stop();
//   //                wait(500);
////                   changeStateSound();
//                   state = 1;
//               }
        case 1:


//               if (hitCount <= 1)
//               {
//                   setSpeed(MOTOR_MAX_SPEED);
//                   state = 0;
//               }

            if (compareBits(code, "111xx"))
            {

                setSpeed(MOTOR_SLOW_SPEED);
                motor.stop();
                wait(500);

                state = 2;
            }


            break;
        case 2:
            if (compareBits(code, "00100"))
            {
                motor.stop();
                wait(500);
                setSpeed(MOTOR_MAX_SPEED);

                state++;
            }
            break;
        case 3:
            break;

        case 4:
            return false;
            break;


    }


    return true;//todo
}

void Section2::evaluateAction(uint8_t code) {


    uint8_t speed1 = MOTOR_MAX_SPEED;
    uint8_t speed2 = MOTOR_MAX_SPEED - 20;
    switch (state)
    {
        case 1:
            if (compareBits(code, "xxx10"))
            {
                speed1 = 100;
                speed2 = 100 / 2;
            }
            else if (compareBits(code, "xxxx1"))
            {
                speed1 = 100;
                speed2 = 0;

            }
            else
            {
                speed1 = 120;
                speed2 = 120 / 2;
            }
            break;
    }



//    if (hitCount > 5)
//    {
//
//        speed1 -= 40 * (hitCount - 5);
//        speed2 = speed1 / 2;
//    }
    switch (state)
    {
        case 0:
        case 1:



            followLine(code, speed1, speed2);

            break;
        case 2:
            motor.adjust(MOTOR_MAX_SPEED, 0);
            wait(20);
            break;
        default:
            followLine(code, speed1, speed2);
//            followLine(code);
            break;
    }


}





/*
 * //
// Created by simon on 4/9/19.
//

#include "Section2.h"

Section2::Section2() {
    setShouldGoStraight(true);
}

bool Section2::evaluateState(uint8_t code) {
//    transmissionUART(hitCount);

    switch (state)
    {

        case 0:
            if (hitCount > 1)
            {
                setSpeed(MOTOR_SLOW_SPEED);
//                motor.stop();
//                wait(500);
                changeStateSound();
                state = 1;
            }
        case 1:

            if (hitCount <= 1)
            {
                setSpeed(MOTOR_MAX_SPEED);
                state = 0;
            }

            if (compareBits(code, "111xx"))
            {

                setSpeed(MOTOR_SLOW_SPEED);
                motor.stop();
                wait(500);

                state++;
            }


            break;
        case 2:
            if (compareBits(code, "00100"))
            {
                motor.stop();
                wait(500);
                setSpeed(MOTOR_MAX_SPEED);

                shouldIncrementHitCount = true;
                hitCount = 0;
                state++;
            }
            break;
        case 3:
            break;

        case 4:
            return false;
            break;


    }


    return true;//todo
}

void Section2::evaluateAction(uint8_t code) {

    switch (state)
    {
        case 0:

        case 1:
        case 3:
        case 4:
//            transmissionUART(hitCount);

            if (shouldIncrementHitCount && compareBits(code, "x1xxx"))
            {
                if (hitCount != 0)
                {
                    hitCount--;

                }
                shouldIncrementHitCount = false;
            }
            else if (compareBits(code, "xxxx1") ||
                     (shouldIncrementHitCount && compareBits(code, "xxx1x")))
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


    switch (state)
    {
        case 1:
//            motor.adjust(getSpeed() - 20, getSpeed());
            leftTurn(code);

            break;
        case 2:
            motor.adjust(MOTOR_MAX_SPEED, 0);
            wait(20);
            break;
        default:
            followLine(code);
            break;
    }


}


void Section2::leftTurn(uint8_t code) {
    if (compareBits(code, "xxxx1")) {
        motor.adjust(0, MOTOR_SLOW_SPEED);
    }
    else{

        motor.adjust(MOTOR_SLOW_SPEED / 2, MOTOR_SLOW_SPEED);
    }
    wait(100);

}

 */