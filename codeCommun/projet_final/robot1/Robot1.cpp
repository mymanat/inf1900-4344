//
// Created by simon on 4/3/19.
//

#include "Robot1.h"


void Robot1::init() {

    setSection(receiveData());
    del.eteindre();
    del.allumer(section);
}


void Robot1::run() {
    moteur.init();
    convertisseur.init();
    bool shouldLoop = true;
    while (shouldLoop)
    {
        convertisseur.update();
        shouldLoop = evaluateState(convertisseur.getIsBlackCode());


        evaluateAction(convertisseur.getIsBlackCode());
    }
}

bool Robot1::evaluateState(uint8_t code) {
    return true;
}

void Robot1::evaluateAction(uint8_t code) {
    suivreLigne(code);

}


bool Robot1::suivreLigne(char code) {
    if (code & 0b00011)
    {
        vitesse = VITESSE_LENT;

        moteur.ajustementMoteur(vitesse / 2, vitesse);
    }
    else if (code & 0b11000)
    {
        vitesse = VITESSE_LENT;
        moteur.ajustementMoteur(vitesse, vitesse / 2);
    }
    else if (code & 0b00100)
    {
        vitesse = VITESSE_MAX;
        moteur.avancer(vitesse);
    }

    return true;
}


uint8_t Robot1::receiveData() {

    timer.init();

    button.init();


    timer.setDurationSec(2);
    uint8_t compteur = 0;
    while (true)
    {

        if (button.getState())
        {

            button.setState(false);
            compteur++;
            if (compteur == 10)
            {
                compteur = 1;
            }
            timer.startTimer();
        }

        if (timer.isDone())
        {
            return compteur;
        }
        //todo: receive from ir
    }

    return compteur;


}


/* Getters & Setters */

uint8_t Robot1::getSection() const {
    return section;
}


uint8_t Robot1::getVitesse() const {
    return vitesse;
}

void Robot1::setVitesse(uint8_t vitesse) {
    Robot1::vitesse = vitesse;
}


void Robot1::setSection(uint8_t section) {
    Robot1::section = section;
}
