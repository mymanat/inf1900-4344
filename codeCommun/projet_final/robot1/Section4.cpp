//
// Created by simon on 4/9/19.
//

#include "Section4.h"


Section4::Section4() {
//    setSpeed(MOTOR_SLOW_SPEED);
    setSpeed(120);//todo
    setShouldGoStraight(true);
}


bool Section4::evaluateState(uint8_t code) {

    if (state % 2 == 0)
    {
        if (compareBits(code, "yy0yy"))
        {
            soundEnterBox();
            state++;
        }
    }
    else
    {
        if (compareBits(code, "11111"))
        {
            soundExitBox();
            state++;
            if (state == 6)
            {
                wait(200);
                return false;
            }
        }

    }


    return true;
}

void Section4::evaluateAction(uint8_t code) {


    if (state % 2 == 0)
    {
        if (!(compareBits(code, "1xxxx") || compareBits(code, "xxxx1")))
        {
//            setSpeed(120);
//
//            setTurnSpeed(120 - 40);
            followLine(code);

//            followLine(code, getSpeed(), getSpeed() - 40);

        }
    }
    else
    {

        if (!compareBits(code, "xx1xx"))
        {
//            setTurnSpeed(120);
//            setSpeed(120);
            uint8_t invertedCode = 0;

            invertedCode |= ((code >> 4) & 1) << 0;
            invertedCode |= ((code >> 3) & 1) << 1;
            invertedCode |= ((code >> 2) & 1) << 2;
            invertedCode |= ((code >> 1) & 1) << 3;
            invertedCode |= ((code >> 0) & 1) << 4;

//            followLine(code, getSpeed() - 40, getSpeed());
//            followLine(code);
            followLine(invertedCode);
        }
        else
        {
            motor.goForward(getSpeed());
        }
    }


}


void Section4::soundEnterBox() {
    speaker.jouerSon(80);
    wait(50);
    speaker.arreterSon();
    wait(20);
    speaker.jouerSon(70);
    wait(50);
    speaker.arreterSon();
}

void Section4::soundExitBox() {
    speaker.jouerSon(70);
    wait(50);
    speaker.arreterSon();
    wait(20);
    speaker.jouerSon(80);
    wait(50);
    speaker.arreterSon();
}


