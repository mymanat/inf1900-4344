//
// Created by simon on 3/18/19.
//

#include "Routine.h"
Routine::Routine() {

    initialisationUART();

}

void Routine::executerCommande(uint8_t commande, uint8_t data) {

    transmissionUART(commande);
    transmissionUART(data);

    if (commande == 0x01) {
        debutExecution = true;
    }
    else if (commande == 0xFF) {
        debutExecution = false;
    }

    else if (debutExecution) {
        switch (commande) {

            case 0x02:
                wait(data * TIMER_COUNT);
                break;
            case 0x44:
                del.allumer(data);
                break;
            case 0x45:
                del.eteindre(data);
                break;
            case 0x48:
                speaker.jouerSon(data);
                break;
            case 0x09:
                speaker.arreterSon();
                break;
            case 0x60:
            case 0x61:
                moteur.arreterMoteurs();
                break;
            case 0x62:
                moteur.avancer(data);
                break;
            case 0x63:
                moteur.reculer(data);
                break;
            case 0x64:
                moteur.tournerDroite();
                break;
            case 0x65:
                moteur.tournerGauche();
                break;
            case 0xC0:
                debutBoucle(data);
                break;
            case 0xC1:
                finBoucle();
                break;
        }
    }
}

void Routine::debutBoucle(uint8_t cpt) {
    adresseBcl = adresse;
    compteurBcl = cpt;
}

void Routine::finBoucle() {
    if (compteurBcl != 0) {
        compteurBcl--;
        adresse = adresseBcl;
    }
}

uint8_t Routine::getAdresse() const {
    return adresse;
}

void Routine::setAdresse(uint8_t adresse) {
    Routine::adresse = adresse;
}

void Routine::addToAdress(uint8_t number) {
    setAdresse(getAdresse() + number);
}
