//
// Created by simon on 4/9/19.
//

#include "Section1.h"

bool Section1::evaluateState(uint8_t code)
{
    switch (state)
    {
    case 0:

        motor.tournerDroite90();
        //If all sensors detect black, change state
        // if (compareBits(code, "00000"))
        // {
        //     ++state;
        // }
        wait(3000);

        motor.tournerGauche90();
        wait(3000);
        break;
    case 1:
        //If a command is received, change state
        if (message != 0)
        {
            ++state;
        }
        break;
    case 2:
        break;
    case 3:
        return false;
        break;
    }

    return true;
}

void Section1::evaluateAction(uint8_t code)
{
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
        //Extract the channel out of the message
        channel = ir.getChannel(message);
        channel = 1;

        //If the channel matches the one we are trying to receive from
        if (channel == 1)
        {

            //Extract the command from the message
            command = ir.getCommand(message) - 1;
            command = 1;

            //Calculate values of x and y
            int y = command / 3;
            int x = command % 3;

            //Execute the movements needed to get on the point specified by the command
            motor.tournerGauche90();

            wait(500);

            motor.goForward(MOTOR_MAX_SPEED);
            wait(tempsMovementX[x]);
            motor.stop();

            wait(500);

            motor.tournerDroite90();

            wait(500);

            motor.goForward(MOTOR_MAX_SPEED);
            wait(tempsMovementY[y]);
            motor.stop();

            speaker.jouerSon(RE);
            wait(1000);
            speaker.arreterSon();
            motor.tournerDroite90();
            wait(500);
            motor.goForward(MOTOR_MAX_SPEED);
            wait(tempsMovementX[x]);
            motor.tournerGauche90();
            motor.goForward(MOTOR_MAX_SPEED);
            wait(500);
            ++state;
        }
        break;
    }
}
