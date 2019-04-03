//
// Created by simon on 3/18/19.
//

#include "DEL.h"




/**
 * Permet d'allumer en rouge la DEL branchée sur la pin "numeroDEL" du PORTA
 * @param numeroDEL Le numero de la DEL à allumer
 */
void DEL::allumer(uint8_t numeroDEL) const {
    setBit(&PORT_DEL, true, getPositionDEL(numeroDEL));
}

void DEL::eteindre(uint8_t numeroDEL) const {
    setBit(&PORT_DEL, false, getPositionDEL(numeroDEL));
}

void DEL::setState(bool state, uint8_t numeroDEL) const {
    if (state) {
        allumer(numeroDEL);
    }
    else{
        eteindre(numeroDEL);
    }
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


