#include <avr/io.h>
#include <stdio.h>

#include "Utils.h"
#include "DEL.h"
#include "Timer.h"
#include <util/delay.h>

#include "Button.h"
#include "wait.h"
#include "PWM.h"
#include "Speaker.h"

int main() {



//    PWM pwm;
//    pwm.ajustementPWM()
    Speaker speaker;
    speaker.playFrequency();
    //speaker.jouerSon(50);

//    DDRC = MODE_SORTIE;
//
//
//
//    double a = 0, b = 255;
//
//    double freq = speaker.Notes[62 - 45];
//
//
//    double tempsCalcule = F_CPU * (1 / freq) / 2 / 256;
//
//
//    while (1) {
//        PORTC = 0b01010101;
//        wait(53);
//        PORTC = 0;
//        wait(b - 53);
//    }




//
//    uint8_t compteur = 0;
//
//
//    DEL del;
//    Timer timer;
//    Button button;
//
//
//    timer.setDurationSec(2);
//
//
//    DDRD = MODE_ENTREE;
//    while (!timer.isDone())
//    {
//
//
//        char test = PIND & 0xff;
//        char * ptr = &test;
//        log_uart(ptr);
//        wait(10);
//
//
//        if (button.getState())
//        {
//
//            button.setState(false);
//            compteur++;
//            if (compteur == 10) {
//                compteur = 0;
//            }
//            timer.startTimer();
//        }
//    }
//
//    //TODO: Envoyer signal avec valeur compteur
//
//    compteur = 0;

//    char test[] = "allo";
//    test[0] = compteur;
//    log_uart(test);


}
