//
// Created by simon on 4/3/19.
//

#include "Robot1.h"


void Robot1::transitionState() {

    motor.init();
    trackerSensor.init();

    shouldGoStraight = false;
    setSpeed(MOTOR_FAST_SPEED);

    motor.stop();

#ifdef DEFINE
    speaker.playSound(SOL3);
#endif


    led.setStateOnboardLED(LED_ONBOARD_RED);

    wait(TRANSITION_DELAY_LONG);
    speaker.stopSound();
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
                DEBUG_SOUND();
                if (!shouldTurnAfterTransition)
                {
                    state = 3;
                }
                else
                {

                    motor.adjust(MOTOR_SLOW_SPEED / 4, MOTOR_SLOW_SPEED);
                    state = 2;
                }

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
#ifdef DEFINE
    speaker.playSound(MI4);
#endif

    motor.stop();
    wait(TRANSITION_DELAY_LONG);

    speaker.stopSound();
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
    robot1.setShouldTurnAfterTransition(isShouldTurnAfterTransition());
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

        motor.adjust(speed, speed);

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
    led.turnOff();

    while (true)
    {
        message = ir.receive();
        if (message != 0)
        {
            channel = ir.getChannel();
            if (channel == 1)
            {
                command = ir.getCommand();
                return command;
            }
        }

        if (button.getState())
        {

            button.setState(false);
            led.setStateOnboardLED(LED_ONBOARD_RED);
            compteur++;
            if (compteur == 10)
            {
                compteur = 1;
            }
            led.turnOff();
            led.turnOn((compteur > LED_COUNT) ? (compteur - LED_COUNT) : compteur);


            timer.startTimer();
        }
        if (timer.getValue() > timer.getDuration() / 8)
        {
            led.setStateOnboardLED(LED_ONBOARD_OFF);
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

bool Robot1::isShouldTurnAfterTransition() const {
    return shouldTurnAfterTransition;
}

void Robot1::setShouldTurnAfterTransition(bool shouldTurn) {
    Robot1::shouldTurnAfterTransition = shouldTurn;
}
