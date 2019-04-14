//
// Created by simon on 4/9/19.
//

#ifndef MAIN_SECTION3_H
#define MAIN_SECTION3_H


#include "Robot1.h"

/**
 * Permet de déterminer le segment
 * On évalue la différence entre le temps où le robot atteint la seconde ligne, et le temps où il atteint la première.
 * Si cette différence est plus grande que le temps de la première ligne multiplié par le facteur, le robot se trouve sur le segment 1 ou 3
 */
#define DELTA_FACTOR 2.4

/**
 * Delais (en nombre de boucles) avant de tempter d'observer une première ligne
 */
#define SECTION3_LINE_EXIT_DELAY 200

/**
 * States:
 * 0: Avance jusqu'à la ligne S5
 * 1: Attend btn interrupt
 * 2: suivreligne jusqu'a ligne noire
 * 3: attend sortie ligne noire
 * 4: attend Premiere ligne
 * 5: attend sortie premiere ligne
 * 6: attend deuxieme ligne
 * 7: attend blanc
 * 8: attend btn interrupt
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

    /**
     * Permet d'enregistrer les temps lors de l'observation des lignes
     * @param code
     */
    void detectLine(uint8_t code);

private:
    uint16_t timeFirstLine = 0;
    uint16_t timeSecondLine = 0;
    uint16_t loopCounter = 0;

    bool leftFirst;

};
//389 :  1129 = 740 _ 1.9
//483 : 1901
//2.9358
//1.9023
#endif //MAIN_SECTION3_H

//583 : 100
