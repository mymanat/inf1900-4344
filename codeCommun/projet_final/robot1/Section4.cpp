//
// Created by simon on 4/9/19.
//

#include "Section4.h"


bool Section4::evaluateState(uint8_t code) {
    setVitesse(VITESSE_LENT);
//    state = 1;//todo remove
    switch (state)
    {
        case 0: case 2:
            if (code == 0b11111) {
                state++;
            }
            break;
        case 1:

            break;
    }
    return true;
}

void Section4::evaluateAction(uint8_t code) {
    changementBoite();
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
            suivreLigne(code, getVitesse(), getVitesse() / 2);
            break;

        case 1:
        case 3:
        case 5:
            suivreLigne(code, getVitesse()/2, getVitesse());
            break;
    }






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
void Section4::changementBoite() {
    speaker.jouerSon(80);
    wait(50);
    speaker.arreterSon();
    wait(20);
    speaker.jouerSon(70);
    wait(50);
    speaker.arreterSon();
}



