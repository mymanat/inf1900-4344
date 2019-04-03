//
// Created by simon on 3/18/19.
//

#include "DEL.h"




/**
 * Permet d'allumer en rouge la DEL branchée sur la pin "numeroDEL" du PORTA
 * @param numeroDEL Le numero de la DEL à allumer
 */
void DEL::allumer(uint8_t numeroDEL) const {
//    PORT_DEL |= 0b01 << numeroDEL;
//    PORT_DEL &= ~(0b10 << numeroDEL);
    setBit(&PORT_DEL, 1, getPositionDEL(numeroDEL));
}

void DEL::eteindre(uint8_t numeroDEL) const {
//    PORT_DEL &= ~(0b11 << numeroDEL);

    setBit(&PORT_DEL, 0, getPositionDEL(numeroDEL));


}

uint8_t DEL::getPositionDEL(uint8_t numeroDEL) const{
    switch (numeroDEL) {
        case 1:
            return POSITION_DEL_1;
            break;
        case 2:
            return POSITION_DEL_2;
            break;
        case 3:
            return POSITION_DEL_3;
            break;
        case 4:
            return POSITION_DEL_4;
            break;
        case 5:
            return POSITION_DEL_5;
            break;
        default:
            DEBUG_PRINT("ERREUR: Mauvais numero de DEL");
            return 0;
            break;
    }
}


DEL::DEL() {
    DDR_DEL = MODE_SORTIE;
}


