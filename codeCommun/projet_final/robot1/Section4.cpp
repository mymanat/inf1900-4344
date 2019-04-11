//
// Created by simon on 4/9/19.
//

#include "Section4.h"


Section4::Section4() {
    setVitesse(MOTOR_SLOW_SPEED);
    setShouldGoStraight(true);
}

bool Section4::evaluateState(uint8_t code) {

    if (state % 2 == 0)
    {
        if (compareBits(code, "x000x"))
        {
            changeBox();
            state++;
        }
    }
    else
    {
        if (compareBits(code, "11111"))
        {
            changeBox();
            state++;
            if (state == 6)
            {
                return false;
            }
        }

    }


    return true;
}

void Section4::evaluateAction(uint8_t code) {


    if (state % 2 == 0)
    {
        if (compareBits(code, "1xxxx") || compareBits(code, "xxxx1"))
        {
            moteur.goForward(getVitesse());

        }

        else
        {
            suivreLigne(code, getVitesse(), getVitesse() / 2);

        }
    }
    else
    {

        if (compareBits(code, "xx1xx"))
        {

            moteur.goForward(getVitesse());
        }
        else
        {
            suivreLigne(code, getVitesse() - 20, getVitesse());
        }
    }


}


/**
 * Permet de jouer le son lors du changement de boite
 */
void Section4::changeBox() {
    speaker.jouerSon(80);
    wait(50);
    speaker.arreterSon();
    wait(20);
    speaker.jouerSon(70);
    wait(50);
    speaker.arreterSon();
}



