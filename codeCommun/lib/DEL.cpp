//
// Created by simon on 3/18/19.
//

#include "DEL.h"


/**
 * Permet d'allumer en rouge la DEL branchée sur la pin "numeroDEL" du PORTA
 * @param numeroDEL Le numero de la DEL à allumer
 */
void DEL::allumer(uint8_t numeroDEL) const {
    PORT_DEL |= 0b01 << numeroDEL;
    PORT_DEL &= ~(0b10 << numeroDEL);
}

void DEL::eteindre(uint8_t numeroDEL) const {
    PORT_DEL &= ~(0b11 << numeroDEL);
}


DEL::DEL() {
    DDR_DEL = MODE_SORTIE;
}


