#include <avr/io.h>
#include "Utils.h"
#include "LED.h"
#include "Timer.h"

#include "Button.h"
#include "Speaker.h"
#include "can.h"
#include "LOG.h"
#include "IRTransceiver.h"


int main() {
    DDRA = MODE_INPUT;
    DDRC = MODE_OUTPUT;
    LED led;

    Timer timer;
    Button button;

    IRTransceiver ir;

    timer.init();
    button.init();

    timer.setDurationSec(2);

    uint8_t counter = 0;

    led.setStateOnboardLED(LED_ONBOARD_GREEN);

    while (true)
    {


        if (button.getState())
        {
            while (button.getState()) {
                led.setStateOnboardLED(LED_ONBOARD_RED);
            }
            led.setStateOnboardLED(LED_ONBOARD_GREEN);

            counter = 1;
            button.setState(false);
            timer.startTimer();


            while (!timer.isDone())
            {

                if (button.getState())
                {
                    while (button.getState()) {
                        led.setStateOnboardLED(LED_ONBOARD_RED);
                    }
                    led.setStateOnboardLED(LED_ONBOARD_GREEN);

                    counter++;
                    button.setState(false);
                    timer.startTimer();
                }
            }

            counter %= 10;
            timer.startTimer();

            led.setStateOnboardLED(LED_ONBOARD_RED);
            while (!timer.isDone())
            {
                ir.transmit(counter, 1);
            }

            for (uint8_t i = 0; i < counter; ++i)
            {

                led.setStateOnboardLED(LED_ONBOARD_OFF);
                wait(200);
                led.setStateOnboardLED(LED_ONBOARD_GREEN);
                wait(200);

            }
            led.setStateOnboardLED(LED_ONBOARD_GREEN);
        }
    }
}
