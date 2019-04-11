//
// Created by simon on 4/9/19.
//

#include "Section1.h"

bool Section1::evaluateState(uint8_t code)
{
    switch (state)
    {
    case 0:
        //If all sensors detect black, change state
        if (compareBits(code, "00000"))
        {
            ++state;
        }
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
        suivreLigne(code);
        break;
    case 1:
        //Stop the motors and wait for a command
        moteur.stop();
        message = ir.receive();
        break;
    case 2:
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
            moteur.tournerGauche90();

            wait(500);

            moteur.goForward(MOTOR_MAX_SPEED);
            wait(tempsMovementX[x]);
            moteur.stop();

            wait(500);

            moteur.tournerDroite90();

            wait(500);

            moteur.goForward(MOTOR_MAX_SPEED);
            wait(tempsMovementY[y]);
            moteur.stop();

            speaker.jouerSon(RE);
            wait(1000);
            speaker.arreterSon();
            ++state;
        }
        break;
    case 3:
        while (1)
        {
        };
        break;
    }
}
