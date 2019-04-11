//
// Created by simon on 4/9/19.
//

#ifndef MAIN_SECTION2_H
#define MAIN_SECTION2_H


#include "Robot1.h"

/**
 * States:
 * 0: avance jusqu´à la courbe
 * 1: ralenti dans la courbe
 * 2: Suivre ligne normal
 * 3:Demi-lune
 */
class Section2 : public Robot1 {
public:

    Section2();

//ralentir dans demi lune pas reaccel
    bool evaluateState(uint8_t code) override;

    void evaluateAction(uint8_t code) override;

private:
    uint8_t hitCount = 0;
    bool shouldIncrementHitCount = true;

};


#endif //MAIN_SECTION2_H
