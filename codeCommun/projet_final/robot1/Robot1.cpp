//
// Created by simon on 4/3/19.
//

#include "Robot1.h"


Robot1::Robot1() {
    init();
}

void Robot1::init() {

//    setSection(receiveData());
//    del.eteindre();
//    del.allumer(section);
}

void Robot1::transitionState() {
    do
    {
        convertisseur.update();
        moteur.ajustementMoteur(0, VITESSE_LENT);
    } while (!compareBits(convertisseur.getIsBlackCode(), "00100"));
    moteur.arreterMoteurs();
}

void Robot1::run() {
    moteur.init();
    convertisseur.init();
    bool shouldLoop = true;
    while (shouldLoop)
    {
        transmissionUART(state);

        convertisseur.update();


        evaluateAction(convertisseur.getIsBlackCode());
        shouldLoop = evaluateState(convertisseur.getIsBlackCode());
    }
    transitionState();
}

bool Robot1::evaluateState(uint8_t code) {
    return true;
}

void Robot1::evaluateAction(uint8_t code) {
    suivreLigne(code);

}

/**
 * Suivre ligne
 * @param code
 * @param speed Vitesse des roues par defaut
 * @param slowWheelSpeed Vitesse de la roue plus lente (pour tourner)
 * @return
 */
bool Robot1::suivreLigne(char code, uint8_t speed, uint8_t slowWheelSpeed) {
//    transmissionUART(state);
//    transmissionUART(speed);
//    transmissionUART(slowWheelSpeed);
//    transmissionUART(0xff);
    if (code & 0b00011)
    {
        moteur.ajustementMoteur(slowWheelSpeed, speed);
    }
    else if (code & 0b11000)
    {
        moteur.ajustementMoteur(speed, slowWheelSpeed);
    }
    else if (code & 0b00100 || (shouldGoStraight))
    {

        moteur.avancer(speed);
    }

    return compareBits(code, "00100");

}

bool Robot1::suivreLigne(char code) {
    return suivreLigne(code, getVitesse(), getVitesse() / 2);

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

bool Robot1::isShouldGoStraight() const {
    return shouldGoStraight;
}

void Robot1::setShouldGoStraight(bool shouldGoStraight) {
    Robot1::shouldGoStraight = shouldGoStraight;
}

