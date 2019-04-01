#include <avr/io.h>

#include "Utils.h"
#include "DEL.h"
#include "Timer.h"
#include <util/delay.h>

#include "Button.h"


int main() {

    initialisationUART();

    uint8_t compteur = 0;


    DEL del;
    Timer timer;
    Button button;


    timer.setDurationSec(2);


    while (!timer.isDone())
    {

        if (button.getState())
        {

            button.setState(false);
            compteur++;
            if (compteur == 10) {
                compteur = 0;
            }
            timer.startTimer();
        }
    }

    //TODO: Envoyer signal avec valeur compteur

    compteur = 0;

//    char test[] = "allo";
//    test[0] = compteur;
//    log_uart(test);


}
