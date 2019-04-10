//
// Created by simon on 4/9/19.
//

#include "Section4.h"


bool Section4::evaluateState(uint8_t code) {
    switch (state)
    {

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



