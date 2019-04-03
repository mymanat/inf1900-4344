//
// Created by simon on 3/18/19.
//

#ifndef MAIN_DEL_H
#define MAIN_DEL_H

#include "Utils.h"

#define DEL_COUNT 5 //Le nombre de DELs

/**
 * Classe Permettant de contrôler la DEL.
 * Celle-ci doit être branchée sur le PORTC (comme défini dans constantes.h), avec le + connecté au bit 1, et le - au bit 2 (pour la première DEL)
 */
class DEL {


public:
    DEL();

    uint8_t getPositionDEL(uint8_t numeroDEL) const;

    void allumer(uint8_t numeroDEL) const;
    void allumer() const;

    void eteindre(uint8_t numeroDEL) const;
    void eteindre() const;


    void setState(bool state, uint8_t numeroDEL) const;
    void setState(bool state) const;

};


#endif //MAIN_DEL_H
