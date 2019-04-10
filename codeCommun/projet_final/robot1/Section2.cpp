//
// Created by simon on 4/9/19.
//

#include "Section2.h"


bool Section2::evaluateState(uint8_t code) {
    convertisseur.setShouldUpdateDel(false);//
    del.eteindre();
    del.allumer(state);

    if (state == 0)
    {
        convertisseur.updateDEL();
    }

    if (state == 0 && code & 0b00001)
    {

        setVitesse(VITESSE_LENT);
        state++;
    }

    if (state == 1 && code & 0b10000)
    {
        setVitesse(VITESSE_MAX);
        state++;
    }
    if (state == 2 && code & 0b00001)
    {
        setVitesse(VITESSE_LENT);
        state++;
    }
    if (state == 3 && code == 0b11111)
    {
        moteur.arreterMoteurs();

        return false;
    }

    return true;//todo
}

void Section2::evaluateAction(uint8_t code) {
    suivreLigne(code);
}
