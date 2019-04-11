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
        if (compareBits(code, "11111"))
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
        moteur.arreterMoteurs();
            message = ir.receive();
        break;
    case 2:
        //Extract the channel out of the message
        channel = ir.getChannel(message);

        //If the channel matches the one we are trying to receive from
        if (channel == 1)
        {

            //Extract the command from the message
            command = ir.getCommand(message);

            //Execute the movements needed to get on the point specified by the command
            switch (command)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            }
        }
        break;
    }
}
