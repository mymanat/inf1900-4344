//
// Created by simon on 4/9/19.
//

#ifndef MAIN_SECTION3_H
#define MAIN_SECTION3_H


#include "Robot1.h"

/**
 * States:
 * 0: Avance jusqu'à la ligne S5
 * 1: Attend btn interrupt
 * 2:suivreligne
 * 3: attend btn interrupt et quitte la loop
 */
class Section3 : public Robot1{

public:

    bool evaluateState(uint8_t code) override;

    void evaluateAction(uint8_t code) override;

    bool suivreLigneSection3(uint8_t code);

private:
    uint8_t numeroDroite = 0;

};


#endif //MAIN_SECTION3_H
