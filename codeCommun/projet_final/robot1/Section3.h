//
// Created by simon on 4/9/19.
//

#ifndef MAIN_SECTION3_H
#define MAIN_SECTION3_H


#include "Robot1.h"

/**
 * Si le loopCounter est plus grand que cette valeur, le robot est sur D1 ou D3
 */
#define DELTA_COUNTER 1800

/**
 * States:
 * 0: Avance jusqu'à la ligne S5
 * 1: Attend btn interrupt
 * 2:suivreligne jusqu'a ligne noire
 * 3: sortie ligne noire
 * 4: Premiere ligne
 * 5: deuxieme ligne
 * 6: wait for press
 */
class Section3 : public Robot1 {

public:

    Section3();

    bool evaluateState(uint8_t code) override;

    void evaluateAction(uint8_t code) override;

/**
 * Permet de suive la ligne sauf si les capteurs aux extrémités détectent du noirs (pour éviter de suive les lignes perpendiculaires)
 * @param code le isBlack code
 * @return Si le robot est centré sur la ligne
 */
    bool followLineSection3(uint8_t code);


/**
 * Permet de déterminer la ligne (D1 D2 D3 ou D4) et d'allumer les DELs en conséquence
 */
    void evaluateLine();


private:
    uint16_t loopCounter = 0;
    bool leftFirst;

};


#endif //MAIN_SECTION3_H
