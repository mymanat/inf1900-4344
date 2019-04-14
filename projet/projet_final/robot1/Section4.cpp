//
// Created by simon on 4/9/19.
//

#include <stdint.h>
#include "Section4.h"


Section4::Section4() {
    setSpeed(MOTOR_SLOW_SPEED);
}


bool Section4::evaluateState(uint8_t code) {
    switch (state)
    {
        /* state % 4 == 0 */
        case 0:
        case 4:
        case 8:
            if (compareBits(code, "1xxx1"))
            {
                soundEnterBox();
                state++;
            }
            break;


            /* state % 2 != 0 */
        case 1:
        case 5:
        case 9:
            if (compareBits(code, "y000y"))
            {

                state++;
            }
            break;
        case 3:
        case 7:
        case 11:
            if (compareBits(code, "0zzz0"))
            {
                state++;

            }
            break;
        case 12:
            if (loopCount >= TRANSITION_DELAY_2)
            {

                led.setStateOnboardLED(LED_ONBOARD_RED);
                motor.goForward(MOTOR_FAST_SPEED);
                wait(TRANSITION_DELAY_2);
                return false;
            }
            break;
            /* else */
        default:
            if (compareBits(code, "1xxx1"))
            {
                soundExitBox();
                state++;
            }
            break;

    }


    /*
     * //todo
     if (state % 2 == 0)
     {
         if (compareBits(code, "y000y"))
         {
             led.setStateOnboardLED(LED_ONBOARD_RED);
             soundEnterBox();
             state++;
             led.setStateOnboardLED(LED_ONBOARD_OFF);
         }
     }
     else
     {
         if (compareBits(code, "11111"))
         {
             led.setStateOnboardLED(LED_ONBOARD_RED);
             soundExitBox();
             led.setStateOnboardLED(LED_ONBOARD_OFF);
             state++;
             if (state == 6)
             {
                 motor.goForward(MOTOR_FAST_SPEED);
                 wait(TRANSITION_DELAY_2);
                 return false;
             }
         }

     }*/


    return true;
}

void Section4::evaluateAction(uint8_t code) {
    if (state == 12)
    {
        loopCount++;
        followLine(code);
        return;

    }


    /* Correspond aux états 0, 4, 8. Les états où il fait suivre la ligne */
    if (state % 4 == 0)
    {
        led.setStateOnboardLED(LED_ONBOARD_GREEN);
        followLine(code);
    }

        /* états 1, 3,5, 7, 9, 11. Les états sur la ligne perpendiculaire*/
    else if (state % 2 != 0)
    {
        led.setStateOnboardLED(LED_ONBOARD_OFF);
        if (compareBits(code, "0000"))
        {

            followLine(code);
//            motor.goForward(getSpeed());
        }
    }

        /* États 2, 6, 10. Dans la boîte */
    else
    {
        if (!compareBits(code, "00000"))
        {

            led.setStateOnboardLED(LED_ONBOARD_GREEN);
            uint8_t speed2 = getSpeed();

            /* Si le capteur 2 ou 4 est actif, on doit tourner plus.*/
            speed2 *= compareBits(code, "xz0zx") ? 0.5 : 0.75;

            followLine(invertBitsPos(code, SENSOR_COUNT), getSpeed(), speed2);
        }
            /* Si les capteurs ne détectent rien, on va tout droit */
        else
        {
            led.setStateOnboardLED(LED_ONBOARD_RED);
            motor.goForward(MOTOR_SLOW_SPEED);
        }
    }

    /*
     * Les états pairs font des followLine() normal.
     */
/*

    if (state % 2 == 0)
    {
        if (!(compareBits(code, "1xxxx") || compareBits(code, "xxxx1")))
        {
            followLine(code);
        }
    }
    else
    {

        if (!compareBits(code, "xx1xx"))
        {

            followLine(invertBitsPos(code, SENSOR_COUNT));
        }
        else if (compareBits(code, "0000"))
        {

            motor.goForward(getSpeed());
        }
    }

*/

}


void Section4::soundEnterBox() {
    speaker.playSound(LA4);
    wait(50);
    speaker.stopSound();
    wait(20);
    speaker.playSound(LA5);
    wait(50);
    speaker.stopSound();
}

void Section4::soundExitBox() {
    speaker.playSound(LA5);
    wait(50);
    speaker.stopSound();
    wait(20);
    speaker.playSound(LA4);
    wait(50);
    speaker.stopSound();
}


