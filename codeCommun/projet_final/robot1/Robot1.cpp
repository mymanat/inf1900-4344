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

void Robot1::run() {
    moteur.init();
    convertisseur.init();
    do
    {
        convertisseur.update();

    } while (suivreLigne());

    moteur.arreterMoteurs();
    Speaker speaker;
    speaker.jouerMelodie3();

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

bool Robot1::suivreLigne() {

    uint8_t v_lent = vitesse_max - 50;

    uint8_t delta = 20;
    char code = convertisseur.getIsBlackCode();

    moteur.arreterMoteurs();
    moteur.setDirection(DIRECTION_AVANCER);

    uint8_t vg = 0, vd = 0;
    //10000
    if (code & 0b10000)
    {

        if (lastDirection == 3) {
            vitesse = vitesse_max;
        }
        else{

            lastDirection = 3;
            vitesse = v_lent;
        }


        vg = vitesse ;
        vd = vitesse;
    }
    else if (code & 0b01000)
    {
//        lastDirection = 3;
        vg = vitesse;
        vd = vitesse - delta;
    }

    else if (code & 0b00001)
    {

        if (lastDirection == 2) {
            vitesse = vitesse_max;

        }
        else{
            lastDirection = 2;
            vitesse = v_lent;

        }

        vg = vitesse;
        vd = vitesse;
    }
    else if (code & 0b00010)
    {
        vg = vitesse - delta;
        vd = vitesse;
    }

    else if (!(code & 0b11011))
    {
//        lastDirection = 1;
        vd = vitesse;
        vg = vitesse;

    }
    if(code & 0b11111 || code == 0b00000)
    {
        switch (lastDirection) {
            case 2:
                moteur.setDirectionMoteur(DIRECTION_RECULER, MOTEUR_DROITE);

                vg = vitesse;
                vd = v_lent;
                break;
            case 3:
                moteur.setDirectionMoteur(DIRECTION_RECULER, MOTEUR_GAUCHE);
                vg = v_lent;
                vd = vitesse;
                break;
        }
    }
    moteur.ajustementMoteur(vg, vd);
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
