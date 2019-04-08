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

    can convertisseur;

    uint16_t irSensor;

    uint16_t valeurLue;
    char str[16];
    initialisationUART();

    IRTransciever transmetteur;
    transmetteur.transmettre(1);

    int reponse;
    IRTransciever receveur;
    reponse = receveur.recevoir();
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
