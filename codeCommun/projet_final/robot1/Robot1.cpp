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
    //moteur.init();
    //convertisseur.init();
    //int cpt = 0;
    //while (cpt < 4)
    //{
       // faireSection();
     //   ++cpt;
    //}
    moteur.init();
    convertisseur.init();
//    do
//    {
//        convertisseur.update();
//
//    } while (suivreLigne());
while(1) {
    convertisseur.update();
    suivreLigne();
}

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
    bool changement = true;
    //int next = 0;
    while(changement)
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

void Robot1::section4(bool & changement) {
    char code = convertisseur.getIsBlackCode();
    if (code & 0b11111)
    {
        changement = !changement;
    }
    if (changement)
    {
        suivreLigne();
    }   
    else
    {
        suivreLigneBoite();
    }
}
void Robot1::suivreLigneBoite()	{
    char code = convertisseur.getIsBlackCode();
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

bool Robot1::suivreLigne() {
    int vitesse = 150;
    int delay = 50;
    int vitesseMax = 255;
//    moteur.setDirection(1);
    if (shouldStop && !convertisseur.isBlack(1) && !convertisseur.isBlack(2) && !convertisseur.isBlack(3) &&
        !convertisseur.isBlack(4) && !convertisseur.isBlack(5))
    {
        shouldStop = false;
        return false;
    }
    if (convertisseur.isBlack(1) && convertisseur.isBlack(2) && convertisseur.isBlack(3) &&
        convertisseur.isBlack(4) && convertisseur.isBlack(5))
    {
//        shouldStop = true;
//        return true;

        return false;
    }
    else if (convertisseur.isBlack(4) && convertisseur.isBlack(5))
    {
        //tourner droite
//        moteur.setDirectionMoteur(1, 0);
        moteur.ajustementMoteur(vitesse, 0);
        wait(delay);
    }

    else if (convertisseur.isBlack(1) && convertisseur.isBlack(2))
    {
        //tourner gauche
//        moteur.setDirectionMoteur(0, 1);
        moteur.ajustementMoteur(0, vitesse);
        wait(delay);
    }
    else
    {
        moteur.setDirection(1);
    }

    if (convertisseur.isBlack(1))
    {
        moteur.ajustementMoteur(0, vitesse);
    }
    else if (convertisseur.isBlack(2))
    {

        moteur.ajustementMoteur(vitesse / 2, vitesse);
    }
    else if (convertisseur.isBlack(5))
    {
        moteur.ajustementMoteur(vitesse, 0);
    }
    else if (convertisseur.isBlack(4))
    {
        moteur.ajustementMoteur(vitesse, vitesse / 2);
    }
    else if (convertisseur.isBlack(3))
    {
        moteur.avancer(vitesse);
    }

    shouldStop = false;
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
