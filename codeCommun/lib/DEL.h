//
// Created by simon on 3/18/19.
//

#ifndef MAIN_DEL_H
#define MAIN_DEL_H

#include "constantes.h"
/**
 * Classe Permettant de contrôler la DEL. Celle-ci doit être branchée sur le PORTA, avec le + connecté au bit 1, et le - au bit 2
 */
class DEL {


public:
    DEL();

    void allumer(uint8_t numeroDEL=0) const;

    void eteindre(uint8_t numeroDEL=0) const;


};


#endif //MAIN_DEL_H
