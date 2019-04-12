#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "LED.h"
#include "Timer.h"
#include <util/delay.h>

#include "Button.h"
#include "wait.h"
#include "PWM.h"
#include "Speaker.h"
#include "can.h"
#include "LOG.h"
#include "IRTransceiver.h"

int main() {
    DDRA = MODE_ENTREE;
    DDRC = MODE_SORTIE;

    Timer timer;
    Button button;

    IRTransceiver ir;

    timer.init();
    button.init();

    timer.setDurationSec(2);

    u_int8_t counter;

    while(true){

        if(button.getState()){

            timer.startTimer();
            counter = 1;
            button.setState(false);
            
            while(!timer.isDone()){

                if(button.getState()){                    
                    counter++;
                    button.setState(false);
                }
            }
        }

        counter %= 10;
        timer.startTimer();

        while(!timer.isDone()){
            ir.transmit(counter, 1);
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
