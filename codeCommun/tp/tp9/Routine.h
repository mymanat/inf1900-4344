//
// Created by simon on 3/18/19.
//

#ifndef MAIN_ROUTINE_H
#define MAIN_ROUTINE_H

#include <avr/io.h>
#include "LOG.h"//todo

#include "Utils.h"

#include "wait.h"
#include "moteurs.h"
#include "PWM.h"
#include "DEL.h"
#include "Speaker.h"


class Routine {

public:
    Routine();

    void executerCommande(uint8_t commande, uint8_t data);

    void debutBoucle(uint8_t cpt);

    void finBoucle();


    uint8_t getAdresse() const;

    void setAdresse(uint8_t adresse);
    void addToAdress(uint8_t number);

private:
    DEL del;
    moteurs moteur;
    Speaker speaker;

    bool debutExecution = false;
    uint8_t adresse = 0;
    uint8_t adresseBcl = 0;
    uint8_t compteurBcl = 0;

};


#endif //MAIN_ROUTINE_H
