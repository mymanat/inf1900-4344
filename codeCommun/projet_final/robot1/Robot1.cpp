//
// Created by simon on 4/3/19.
//

#include "Robot1.h"


Robot1::Robot1() {
    setSection(receiveData());

//    del.eteindre();
//    del.allumer(section);
    del.allumer();

}

void Robot1::run() {
    //moteur.init();
    //convertisseur.init();
    int cpt = 0;
    while (cpt < 4)
    {
        faireSection();
        ++cpt;
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

    while(changement == 0)
    {
        switch (section){
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

void Robot1::suivreLigne() {
    moteur.avancer(128);
    if (convertisseur.isBlack(1))
    {
        moteur.ajustementMoteur(VITESSE_ROTATION, VITESSE_ROTATION / 2);
    }
    if (convertisseur.isBlack(2))
    {
        moteur.tournerGauche();
    }
    if (convertisseur.isBlack(4))
    {
        moteur.tournerDroite();
    }
    if (convertisseur.isBlack(5))
    {
        moteur.ajustementMoteur(VITESSE_ROTATION / 2, VITESSE_ROTATION);
    }
}

void Robot1::setSection(uint8_t section) {
    Robot1::section = section;
}


uint8_t Robot1::receiveData() {
    uint8_t compteur = 0;
    timer.setDurationSec(2);

    button.init();

    uint8_t data = 0;
    del.allumer();
    while (data == 0)
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
            del.eteindre();
            data = compteur;
        }

        //todo: data receive from IR
    }

    del.allumer();
    return compteur;
}
