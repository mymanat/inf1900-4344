//
// Created by simon on 4/9/19.
//

#include "Section4.h"


bool Section4::evaluateState(uint8_t code) {
    setVitesse(VITESSE_LENT);
//    state = 1;//todo remove
    if (state % 2 == 0)
    {
        if (state == 6 && compareBits(code, "xxxx1"))
        {
            moteur.arreterMoteurs();
            return false;
        }
        if (compareBits(code, "xx0xx"))
        {
            changementBoite();
            state++;
        }
    }
    else
    {
        if (compareBits(code, "xx1xx"))
        {
            changementBoite();
            state++;
        }

    }

    return true;
}

void Section4::evaluateAction(uint8_t code) {
    if (state % 2 == 0) {
        //State = 2 4 6: Suivre ligne normal
        suivreLigne(code, getVitesse(), getVitesse() / 2);
    }
    else{
        suivreLigne(code, getVitesse() / 2, getVitesse());
    }

}

void Section4::changementBoite() {
    speaker.jouerSon(80);
    wait(50);
    speaker.arreterSon();
    wait(20);
    speaker.jouerSon(70);
    wait(50);
    speaker.arreterSon();
}



