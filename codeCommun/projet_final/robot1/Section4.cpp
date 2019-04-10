//
// Created by simon on 4/9/19.
//

#include "Section4.h"


bool Section4::evaluateState(uint8_t code) {
    setVitesse(VITESSE_LENT);
    state = 1;//todo remove
    switch (state)
    {
//        case 0: case 2:

    }
    return true;
}

void Section4::evaluateAction(uint8_t code) {
    /*switch (state)
    {
        default:
            suivreLigne(code);
            break;
    }*/

//    moteur.init();
    uint8_t code_inverted = code;
    switch (state)
    {
        case 0:
        case 2:
        case 4:
            break;

        case 1:
        case 3:
        case 5:
            setBit(&code_inverted, (code & 0b10000), 0);
            setBit(&code_inverted, (code & 0b01000), 1);
            setBit(&code_inverted, (code & 0b00010), 3);
            setBit(&code_inverted, (code & 0b00001), 4);
            setBit(&code_inverted, !(code & 0b00100), 2);
            break;
    }


    suivreLigne(code_inverted);




/*

    bool changement = true; //todo ???
    if (code & 0b11111)
    {
        changement = !changement;
    }
    if (changement)
    {
        suivreLigne(code);
    }
    else
    {
        suivreLigneBoite(code);
    }
*/




}


void Section4::suivreLigneBoite(uint8_t code) {
    //invert code??

    moteur.avancer(128);
    if (convertisseur.isBlack(1))
    {
        moteur.ajustementMoteur(VITESSE_ROTATION / 2, VITESSE_ROTATION);
    }
    if (convertisseur.isBlack(2))
    {
        moteur.tournerDroite();
    }
    if (convertisseur.isBlack(4))
    {
        moteur.tournerGauche();
    }
    if (convertisseur.isBlack(5))
    {
        moteur.ajustementMoteur(VITESSE_ROTATION, VITESSE_ROTATION / 2);
    }
}



