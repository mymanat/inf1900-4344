#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "LED.h"
#include "Timer.h"
#include <util/delay.h>

#include "Button.h"
#include "wait.h"
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

            counter = 1;
            button.setState(false);
            timer.startTimer();

            //_delay_ms(100);

            while (!timer.isDone())
            {

                if (button.getState())
                {
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
    /*

    IRTransceiver transmetteur;

        Timer timer;
        Button button;

        timer.init();

        button.init();


        timer.setDurationSec(2);
        uint8_t compteur = 0;

        IRTransceiver ir;


        while (true)
        {


            if (button.getState())
            {

                button.setState(false);
                compteur++;
                if (compteur == 10)
                {
                    compteur = 1;
                }
                timer.startTimer();
            }

            if (timer.isDone())
            {
                ir.transmit(compteur, 1);
            }
            
        }
*/
}
