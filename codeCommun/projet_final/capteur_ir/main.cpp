#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "memoire_24.h"
#include "constantes.h"
#include "wait.h"
#include "LOG.h"
#include "can.h"
#include "IRTransciever.h"
#include "DEL.h"

int main()
{
    DDRA = MODE_ENTREE;
    DDRC = MODE_SORTIE;
    DDRB = MODE_ENTREE;
    DDRD = MODE_SORTIE;

    can convertisseur;


    uint16_t irSensor;

    PORTC = 0x00;

    uint16_t valeurLue;
    char str[16];
    initialisationUART();

    IRTransciever ir;
    int message = 0;
    int channel = 0;
    int command = 0;

    DEL del;

    while (1)
    {
        message = ir.recevoir();
        command = ir.getCommand(message);
        channel = ir.getChannel(message);

        /*if(message != 0){
            transmissionUART(message);
            transmissionUART(channel);
            transmissionUART(command);
        }   */     

        if(channel == 1){
            switch(command){
                case 0:
                    del.eteindre();
                break;
                case 1:
                    del.allumer(1);
                break;
                case 2:
                    del.allumer(2);
                break;
                case 3:
                    del.allumer(3);
                break;
                case 4:
                    del.allumer(4);
                break;
                case 5:
                    del.allumer(5);
                break;
            }
        }

        /*if(message == 0x21){
            PORTC = 0x05;
        }*/
            


        /*irSensor = convertisseur.lecture(6);

        itoa(irSensor, str, 10);

        log_uart(str);
        log_uart("\n");

        if(irSensor < 100){
            setBit(&PORTC, 1, POSITION_DEL_5);
            _delay_ms(2000);
        }
        else{
            setBit(&PORTC, 0, POSITION_DEL_5);
        }*/



    }

}
