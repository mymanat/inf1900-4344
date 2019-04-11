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
#include "IRTransciever.h"

int main()
{
    DDRA = MODE_ENTREE;
    DDRC = MODE_SORTIE;

    can convertisseur;

    uint16_t irSensor;

    uint16_t valeurLue;
    char str[16];
    initialisationUART();

    IRTransciever transmetteur;
    int cpt = 0;

    while(1){

        for(int i = 0; i < 4; ++i){
            transmetteur.transmettre(cpt, 1);
        }
        
        //_delay_ms(50);
        cpt++;
        cpt %= 6;
    }
    int reponse;
    IRTransciever receveur;
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
