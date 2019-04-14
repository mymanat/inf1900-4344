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
    setSpeed(MOTOR_MAX_SPEED);

    motor.stop();

    speaker.jouerSon(SOL3);
    led.setStateOnboardLED(LED_ONBOARD_RED);

    wait(500);
    speaker.arreterSon();
    state = 0;
    uint8_t code = 0;
    do
    {

        trackerSensor.update();
        code = trackerSensor.getSensorStateCode();
        if (state == 0)
        {
            motor.goForward(getSpeed());
            /* Suit la ligne jusqu'au virage */
            if (followLine(code) || compareBits(code, "0xzz1"))
            {
                motor.stop();
                changeStateSound();
                motor.adjust(40, 100);
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

    led.setStateOnboardLED(LED_ONBOARD_OFF);
    speaker.jouerSon(MI4);
    motor.stop();
    wait(500);
    speaker.arreterSon();
}

void Robot1::run() {
    motor.init();
    trackerSensor.init();
    bool shouldLoop = true;
    while (shouldLoop)
    {
        trackerSensor.update();
        evaluateAction(trackerSensor.getSensorStateCode());
        shouldLoop = evaluateState(trackerSensor.getSensorStateCode());
    }

    Robot1 robot1;
    robot1.transitionState();
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

    return compareBits(code, "00000");
}

bool Robot1::followLine(char code) {
    return followLine(code, getSpeed(), getSpeed() / 2);
}

uint8_t Robot1::receiveData() {

    Timer timer;
    Button button;
    LED led;
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
            led.setStateOnboardLED(LED_ONBOARD_RED);
            wait(100);
            led.setStateOnboardLED(LED_ONBOARD_OFF);
            compteur++;
            if (compteur == 10)
            {
                compteur = 1;
            }
            timer.startTimer();
        }

        if (compteur != 0 && timer.isDone())
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
