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

/**
 * Le robot va suivre la ligne jusqu´au virage à gauche. Il va effectuer ce virage de 90 degrés et s'arrêter
 */
void Robot1::transitionState() {
    state = 0;
    uint8_t code = 0;
    do
    {

        trackerSensor.update();
        code = trackerSensor.getIsBlackCode();
        if (state == 0)
        {
            /* Suit la ligne jusqu'au virage */
            suivreLigne(code);
            if (compareBits(code, "00xx1"))
            {
                state++;
            }
        }
        else
        {
            /* Virage */
            moteur.ajustementMoteur(0, VITESSE_LENT);
            if (compareBits(code, "00100"))
            {
                state++;
            }
        }


    } while (state < 3);
    moteur.arreterMoteurs();
}

void Robot1::run() {
    moteur.init();
    trackerSensor.init();
    bool shouldLoop = true;
    while (shouldLoop)
    {

        trackerSensor.update();


        evaluateAction(trackerSensor.getIsBlackCode());
        shouldLoop = evaluateState(trackerSensor.getIsBlackCode());
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
    if (compareBits(code, "00xzz"))
    {
        moteur.ajustementMoteur(slowWheelSpeed, speed);
    }
    else if (compareBits(code, "zzx00"))
    {
        moteur.ajustementMoteur(speed, slowWheelSpeed);
    }
    else if (compareBits(code, "xx1xx") || (shouldGoStraight))
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

