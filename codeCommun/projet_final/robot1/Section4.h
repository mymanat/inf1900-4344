//
// Created by simon on 4/9/19.
//

#ifndef MAIN_SECTION4_H
#define MAIN_SECTION4_H


#include "Robot1.h"
/**
 * States:
 * 0: suivre ligne
 * 1: boite1
 * 2: suivre ligne
 * 3: boite2:
 * 4: suivre ligne
 */
class Section4 : public Robot1 {
public:
    Section4();

    bool evaluateState(uint8_t code) override;

    void evaluateAction(uint8_t code) override;

    void changementBoite();
};


#endif //MAIN_SECTION4_H
