//
// Created by simon on 4/3/19.
//

#include "Robot1.h"


Robot1::Robot1() {

}

void Robot1::init() {

    setSection(receiveData());
    del.eteindre();
    del.allumer(section);
}

void Robot1::realign() {

    char code = convertisseur.getIsBlackCode();
    while (code != 0b00100) {
        if (code & 0b11000) {
            moteur.ajustementMoteur(vitesse_lent, 0);
        }

        else if (code & 0b00011) {

            moteur.ajustementMoteur(0, vitesse_lent);

        }


    }
}

void Robot1::run() {
    moteur.init();
    convertisseur.init();
//    do
//    {
//        convertisseur.update();
//
//    } while (suivreLigne());

    while (1)
    {
        convertisseur.update();
        char code = convertisseur.getIsBlackCode();
//
        transmissionUART(state);
        transmissionUART(code);

        transmissionUART(0xff);
        suivreLigne(code);
//
//
//        realign();
//
//        if (code & 0b00001) {
//
//
//            realign();
//        }
//
////        suivreLigne(code);
//        switch (state)
//        {
//        case 0: case 1:
//                suivreLigne(code);
//                break;
//        }
    }


}


void Robot1::changerSection() {
    if (section == 4)
    {
        section = 1;
    }
    else
    {
        ++section;
    }
}

void Robot1::faireSection() {
    int changement = 0;

    switch (section)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            convertisseur.update();
            section4(changement);
            break;
    }
    changerSection();
}

void Robot1::section4(int & changement) {
//    if (path < -10)
//    {
//        moteur.tournerGauche();
//    }
//    else if (path > 10)
//    {
//        moteur.tournerDroite();
//    }
//    else
//    {
//        moteur.avancer(128);
//    }
}

bool Robot1::suivreLigne(char code) {
    if (code & 0b00001)
    {
        moteur.ajustementMoteur(0, vitesse);
    }
    else if (code & 0b10000)
    {
        moteur.ajustementMoteur(vitesse, 0);
    }

    else if (code & 0b00010)
    {

        moteur.ajustementMoteur(vitesse / 2, vitesse);
    }
    else if (code & 0b01000)
    {
        moteur.ajustementMoteur(vitesse, vitesse / 2);
    }
    else if (code & 0b00100)
    {
        moteur.avancer(vitesse);
    }

    return true;
}

void Robot1::setSection(uint8_t section) {
    Robot1::section = section;
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
