#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "DEL.h"
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

    //can convertisseur;

    //uint16_t irSensor;

    //uint16_t valeurLue;
    //char str[16];
    //initialisationUART();

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







    /*int cpt = 0;

    while(1){

        for(int i = 0; i < 2; ++i){
            transmetteur.transmit(cpt, 1);
        }
        
        //_delay_ms(50);
        cpt++;
        cpt %= 6;
    }*/
    //int reponse;
    //IRTransceiver receveur;
    //reponse = receveur.recevoir();




    // Speaker sp;
    // sp.playFrequency();
    // while (1)
    // {
    //     irSensor = convertisseur.lecture(1);

    //     itoa(irSensor, str, 10);

    //     log_uart(str);
    //     log_uart("\n");
    // }
}
