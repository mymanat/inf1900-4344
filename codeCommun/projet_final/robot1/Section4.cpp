//
// Created by simon on 4/9/19.
//

#include "Section4.h"


Section4::Section4() {
    setVitesse(VITESSE_LENT);
    setShouldGoStraight(true);
    state = 7;
}

bool Section4::evaluateState(uint8_t code) {
//    state = 1;//todo remove
//    transmissionUART(code);
//    transmissionUART(compareBits(code, "xxxx1"));
//    transmissionUART(0xff);

    if (state == 6)
    {
        if (compareBits(code, "xxxx0"))
        {
            state = 7;
        }
        return true;
    }
    if (state == 7)
    {
        if (compareBits(code, "xx111"))
        {
            moteur.arreterMoteurs();
            return false;
        }
        return true;
    }

    if (state % 2 == 0)
    {

//        if (state == 6 && compareBits(code, "xxxx1"))
////        if (state == 6 && code & 0b00001)
//        {
//            moteur.arreterMoteurs();
//            return false;
//        }
        if (compareBits(code, "x000x"))
        {
            changementBoite();
            state++;
        }
    }
    else
    {
        if (compareBits(code, "11111"))
        {
            changementBoite();
            state++;
        }

    }


    return true;
}

void Section4::evaluateAction(uint8_t code) {


    if (state % 2 == 0 || state == 7)
    {
        if (compareBits(code, "1xxxx") || compareBits(code, "xxxx1"))
        {
            moteur.avancer(getVitesse());

        }

        else
        {
            suivreLigne(code, getVitesse(), getVitesse() / 2);

        }
    }
    else
    {

        if (compareBits(code, "x1xxx") || compareBits(code, "xx1xx") || compareBits(code, "xxx1x"))
        {
            moteur.avancer(getVitesse());

        }
        else
        {

            suivreLigne(code, getVitesse(), getVitesse() * 2);
        }
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



