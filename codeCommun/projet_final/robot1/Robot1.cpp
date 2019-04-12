//
// Created by simon on 4/3/19.
//

#include "Robot1.h"


Robot1::Robot1() {
    init();


}

void Robot1::init() {

}

void Robot1::transitionState() {

    motor.init();
    trackerSensor.init();

    shouldGoStraight = false;
    setSpeed(150);


    motor.stop();

    changeStateSound();//todo

    wait(500);
    state = 0;
    uint8_t code = 0;
    do
    {

        trackerSensor.update();
        code = trackerSensor.getSensorStateCode();
        if (state == 0)
        {
            /* Suit la ligne jusqu'au virage */
            followLine(code);
            if (compareBits(code, "00xx1"))
            {
                motor.adjust(40, 100);
                wait(1000);
                state++;
            }
        }
        else
        {
            /* Virage */
            if (compareBits(code, "00100"))
            {
                state++;
            }
        }


    } while (state < 3);

    motor.stop();
    wait(500);
}

void Robot1::run() {
    motor.init();
    trackerSensor.init();
    bool shouldLoop = true;
    while (shouldLoop)
    {
        //transmissionUART(state);//todo

        trackerSensor.update();


        evaluateAction(trackerSensor.getSensorStateCode());
        shouldLoop = evaluateState(trackerSensor.getSensorStateCode());
    }

    transitionState();
}

bool Robot1::evaluateState(uint8_t code) {
    return true;
}

void Robot1::evaluateAction(uint8_t code) {
    followLine(code);

}


bool Robot1::followLine(char code, uint8_t speed, uint8_t slowWheelSpeed) {

    if (compareBits(code, "00xzz"))
    {
        motor.adjust(slowWheelSpeed, speed);
    }
    else if (compareBits(code, "zzx00"))
    {
        motor.adjust(speed, slowWheelSpeed);
    }
    else if (compareBits(code, "xx1xx") || (shouldGoStraight))
    {

        motor.goForward(speed);
    }

    return compareBits(code, "00100");

}

bool Robot1::followLine(char code) {
    return followLine(code, getSpeed(), getSpeed()/2);

}


uint8_t Robot1::receiveData() {
    timer.init();

    button.init();


    timer.setDurationSec(2);
    uint8_t compteur = 0;

    IRTransceiver ir;
    int message = 0;
    int channel = 0;
    int command = 0;

    while (true)
    {
        message = ir.receive();
        if (message != 0)
        {
            channel = ir.getChannel(message);
            if (channel == 1)
            {
                command = ir.getCommand(message);
                if (command >= 1 && command <= 4)
                {
                    return command;
                }
            }
        }

        if (button.getState())
        {

            button.setState(false);
            compteur++;
            if (compteur == 10)
            {
                compteur = 1;
            }
            timer.startTimer();
        }

        if (timer.isDone())
        {
            return compteur;
        }
    }

    return compteur;


}


/* Getters & Setters */



uint8_t Robot1::getSpeed() const {
    return speed;
}

void Robot1::setSpeed(uint8_t speed) {
    Robot1::speed = speed;
}


bool Robot1::isShouldGoStraight() const {
    return shouldGoStraight;
}

void Robot1::setShouldGoStraight(bool shouldGoStraight) {
    Robot1::shouldGoStraight = shouldGoStraight;
}


