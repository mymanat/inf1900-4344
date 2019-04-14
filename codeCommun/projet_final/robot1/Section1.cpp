//
// Created by simon on 4/9/19.
//

#include "Section1.h"

bool Section1::evaluateState(uint8_t code) {
    switch (state)
    {
        case 0:
            //If all sensors detect black, change state
            if (compareBits(code, "00000"))
            {
                state = 1;
            }
            break;
        case 1:
            //If a command is received, change state
            if (message != 0)
            {
                state = 2;
                led.setStateOnboardLED(LED_ONBOARD_RED);
            }
            break;
        case 2:
            break;
        case 3:
            if (!compareBits(code, "00000"))
            {
                speaker.jouerSon(RE);

                state = 4;
            }
        case 4:
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
            //Stop the motors and wait for a command
            motor.stop();
            message = ir.receive();
            break;
        case 2:
            wait(1000);
            led.setStateOnboardLED(LED_ONBOARD_OFF);
            //Extract the channel out of the message
            channel = ir.getChannel(message);

            //Extract the command from the message
            command = ir.getCommand(message) - 1;

            //If the channel matches the one we are trying to receive from
            if (channel == 1)
            {

                //Calculate values of x and y
                int y = command / 3;
                int x = command % 3;

                //Execute the movements needed to get on the point specified by the command
                motor.tournerGauche90();

                wait(2000);

                motor.goForward(255);
                wait(tempsMovementX[x]);
                motor.stop();

                wait(2000);

                motor.tournerDroite90();

                wait(2000);

                motor.goForward(255);
                wait(tempsMovementY[y]);
                motor.stop();

                speaker.jouerSon(RE);
                wait(2000);
                speaker.arreterSon();

                motor.tournerDroite90();
                wait(2000);

                motor.goForward(255);
                wait(tempsMovementX[x]);
                motor.stop();

                wait(2000);

                motor.tournerGauche90();

                wait(2000);

                //motor.goForward(MOTOR_MAX_SPEED);
                //wait();
                state = 3;
            }
            break;
        case 3:
            if (cpt <= 400)
            {
                if (cpt < 200)
                {
                    motor.adjust(40, 100);
                }
                else
                {
                    motor.adjust(100, 40);
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
