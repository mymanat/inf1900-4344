//
// Created by simon on 4/9/19.
//

#include "Section1.h"

Section1::Section1() {

    setSpeed(MOTOR_SLOW_SPEED);
}


bool Section1::evaluateState(uint8_t code) {
    switch (state)
    {
        case 0:

            //If all sensors detect black, change state
            if (compareBits(code, "00000"))
            {
                setSpeed(MOTOR_FAST_SPEED);

                //Stop the motors and wait for a command
                motor.stop();
                command = receiveData() - 1;
                motor.init();
                trackerSensor.can::init();
                ++state;

            }
            break;
        case 1:
            break;
        case 2:
            if (!compareBits(code, "00000"))
            {
                //speaker.playSound(RE);

                ++state;
            }
            break;
        case 3:
            return false;
            break;
    }

    return true;
}

void Section1::evaluateAction(uint8_t code) {
    switch (state)
    {
        case 0:
            //Follow the line until the sensors detect the horizontal line
            followLine(code);
            break;
        case 1:
        {

            //Calculate values of x and y
            int y = command / 3;
            int x = command % 3;

            //Execute the movements needed to get on the point specified by the command
            motor.turnLeft90();

            wait(TRANSITION_DELAY_VERY_LONG);

            motor.goForward(MOTOR_MAXIMUM_SPEED);
            wait(tempsMovementX[x]);
            motor.stop();

            wait(TRANSITION_DELAY_VERY_LONG);

            motor.turnRight90();

            wait(TRANSITION_DELAY_VERY_LONG);

            motor.goForward(MOTOR_MAXIMUM_SPEED);
            wait(tempsMovementY[y]);
            motor.stop();

            speaker.playSound(RE);
            wait(3 * DELAY_1_SEC);
            speaker.stopSound();

            motor.turnRight90();

            wait(TRANSITION_DELAY_VERY_LONG);
            speaker.playSound(RE);
            wait(3 * DELAY_1_SEC);


            speaker.stopSound();

            motor.goForward(MOTOR_MAXIMUM_SPEED);
            wait(tempsMovementX[x]);
            motor.stop();

            wait(TRANSITION_DELAY_VERY_LONG);

            motor.turnLeft90();

            wait(TRANSITION_DELAY_VERY_LONG);

            ++state;
        }
            break;
        case 2:
            motor.setDirection(MOTOR_DIRECTION_FORWARD);
            if (cpt <= 2500)
            {
                if (cpt < 1250)
                {
                    motor.adjust(MOTOR_SLOW_SPEED, MOTOR_SLOW_SPEED / 2);
                }
                else
                {
                    motor.adjust(MOTOR_SLOW_SPEED / 2, MOTOR_SLOW_SPEED);
                }
                ++cpt;
            }
            else
            {
                cpt = 0;
            }

            break;
    }
}


