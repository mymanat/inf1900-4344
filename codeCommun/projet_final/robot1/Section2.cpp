//
// Created by simon on 4/9/19.
//

#include "Section2.h"

Section2::Section2() {
    speaker.jouerSon(RE);
    wait(500);
    setShouldGoStraight(true);
}

bool Section2::evaluateState(uint8_t code) {

    switch (state)
    {

        case 0:
            if (hitCount > 1) {
                setVitesse(VITESSE_LENT);
                moteur.arreterMoteurs();
                changeStateSound();
                state = 1;
            }
        case 1:

            if (hitCount <= 1)
            {
                setVitesse(VITESSE_MAX);
                state = 0;
            }

            if (compareBits(code, "11100")) {

                setVitesse(VITESSE_LENT);

                state++;
            }


            break;
        case 2:
            if (compareBits(code, "00100")) {
                setVitesse(VITESSE_MAX);
                state++;
            }
            break;
    }


    return true;//todo
}

void Section2::evaluateAction(uint8_t code) {

    switch (state)
    {
        case 0:
        case 1:
            transmissionUART(hitCount);

            if (shouldIncrementHitCount && compareBits(code, "x1xxx"))
            {
                if (hitCount != 0) {
                    hitCount--;

                }
                shouldIncrementHitCount = false;
            }
            else if (shouldIncrementHitCount && compareBits(code, "xxx1x"))
            {
                hitCount++;
                shouldIncrementHitCount = false;
            }
            else if (compareBits(code, "00100"))
            {
                shouldIncrementHitCount = true;
            }

            break;
    }


    switch (state) {
        case 2:
            moteur.ajustementMoteur(VITESSE_MAX, 0);
            break;
        default:
            suivreLigne(code);
            break;
    }


}


