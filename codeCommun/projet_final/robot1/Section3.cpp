//
// Created by simon on 4/9/19.
//

#include "Section3.h"

Section3::Section3() {
    setSpeed(MOTOR_SLOW_SPEED);
}


bool Section3::evaluateState(uint8_t code) {

    if (state > 3 && state < 8)
    {
        loopCounter++;
        if (compareBits(code, "00000"))
        {
            led.setStateOnboardLED(LED_ONBOARD_RED);
#ifdef DEBUG
            uint8_t time1a = timeFirstLine >> 8;
                uint8_t time1b = timeFirstLine & 0xff;
                uint8_t time2a = timeSecondLine >> 8;
                uint8_t time2b = timeSecondLine & 0xff;

                transmitUART(time1a);
                transmitUART(time1b);
                transmitUART(0xff);
                transmitUART(time2a);
                transmitUART(time2b);
#endif
            motor.stop();
            trackerSensor.setShouldUpdateDel(false);

            evaluateLine();
            button.init();
            state = 8;

        }
    }
    switch (state)
    {
        case 0:
            if (compareBits(code, "11111"))
            {

                led.setStateOnboardLED(LED_ONBOARD_RED);
                motor.stop();
                button.init();
                state++;

            }
            break;
        case 1:
            while (button.getState())
            {
                led.setStateOnboardLED(LED_ONBOARD_GREEN);
                motor.init();
                state = 2;
            }
            break;
        case 2:
            led.setStateOnboardLED(LED_ONBOARD_OFF);

            if (compareBits(code, "11111"))
            {
                led.setStateOnboardLED(LED_ONBOARD_GREEN);
                state++;
            }
            break;
        case 3:
            if (compareBits(code, "0y1y0"))
            {
                led.setStateOnboardLED(LED_ONBOARD_OFF);
                state++;
            }
            break;
        case 4:
        case 6:
            checkLineDetection(code);
            break;
        case 5:
            if (compareBits(code, "0x1x0"))
            {
                led.setStateOnboardLED(LED_ONBOARD_OFF);
                state++;
            }
            break;

        case 7:

            break;
        case 8:
            motor.stop();
            if (button.getState())
            {

                while (button.getState())
                {
                    led.setStateOnboardLED(LED_ONBOARD_GREEN);
                }
                led.setStateOnboardLED(LED_ONBOARD_OFF);
                trackerSensor.setShouldUpdateDel(true);
                motor.init();
                return false;
            }
            break;

    }
    return true;
}

void Section3::checkLineDetection(uint8_t code) {
    if (loopCounter < 200 || compareBits(code, "0xxx0"))
    {
        return;

    }
    if (timeFirstLine == 0)
    {
        timeFirstLine = loopCounter;

        leftFirst = compareBits(code, "00xx1");
    }

    else
    {
        timeSecondLine = loopCounter;
    }
    led.setStateOnboardLED(LED_ONBOARD_GREEN);

    state++;


}

void Section3::evaluateLine() {
    led.turnOff();
    uint8_t id = 0;

    if (timeSecondLine - timeFirstLine > timeFirstLine * 2.2)
    {

        /* D1 ou D3 */
        id = leftFirst ? 1 : 3;
    }
    else
    {
        /* D2 ou D4 */
        id = leftFirst ? 2 : 4;
    }

    led.turnOn(id);
}

void Section3::evaluateAction(uint8_t code) {

    followLine(code);

}


