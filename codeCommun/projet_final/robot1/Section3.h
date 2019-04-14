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
 * 3: attend sortie ligne noire
 * 4: attend Premiere ligne
 * 5: attend sortie premiere ligne
 *
 * 6: attend deuxieme ligne
 * 7: attend white
 * 8: attend btn
 */
class Section3 : public Robot1 {

public:

    Section3();

    bool evaluateState(uint8_t code) override;

    void evaluateAction(uint8_t code) override;



/**
 * Permet de déterminer la ligne (D1 D2 D3 ou D4) et d'allumer les DELs en conséquence
 */
    void evaluateLine();

    void checkLineDetection(uint8_t code);

private:
    uint16_t  timeFirstLine = 0;
    uint16_t timeSecondLine = 0;
    uint16_t loopCounter = 0;

    bool leftFirst;

};


#endif //MAIN_SECTION3_H
