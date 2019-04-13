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
#include "IRTransceiver.h"
#include "LED.h"

int main()
{
    DDRA = MODE_INPUT;
    DDRC = MODE_OUTPUT;
    DDRB = MODE_INPUT;
    DDRD = MODE_OUTPUT;

    //can convertisseur;

    //uint16_t irSensor;

    PORTC = 0x00;

    //uint16_t valeurLue;
    //char str[16];
    initialisationUART();

    IRTransceiver ir;
    int message = 0;
    int channel = 0;
    int command = 0;

    LED led;

    while (1)
    {
        message = ir.receive();
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
                    led.turnOff();
                break;
                case 1:
                    led.turnOn(1);
                break;
                case 2:
                    led.turnOn(2);
                break;
                case 3:
                    led.turnOn(3);
                break;
                case 4:
                    led.turnOn(4);
                break;
                case 5:
                    led.turnOn(5);
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
