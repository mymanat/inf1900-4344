//
// Created by simon on 4/9/19.
//

#include "Section2.h"

Section2::Section2() {
    state = 0;
}

bool Section2::evaluateState(uint8_t code) {



    if (state == 0 && code & 0b00001)
    {
        moteur.arreterMoteurs();
        wait(500);

        state++;
    }

    else if (state == 1 && code & 0b10000)
    {
        moteur.arreterMoteurs();
        wait(500);
        state++;
    }
    else if (state == 2 && code & 0b00001)
    {
        state++;
    }
    else if (state == 3 && code == 0b11111)
    {
        moteur.arreterMoteurs();

//        return false;
    }

    else
    {
        return true;
    }

    speaker.jouerSonDebugState(state);
    return true;//todo
}

void Section2::evaluateAction(uint8_t code) {
    switch (state)
    {
        case 0:
            suivreLigne(code, getVitesse(), getVitesse());

        case 1:
            if (code & 0b01100)
            {
                suivreLigne(code, VITESSE_LENT, VITESSE_LENT / 2);


            }
            else
            {
                moteur.ajustementMoteur(VITESSE_LENT / 3, VITESSE_LENT);

            }
            break;

        default:
//            suivreLigne(code, getVitesse(), getVitesse());
//            suivreLigne(code);
            suivreLigne(code, getVitesse(), getVitesse() - 10);
            break;
    }

}
