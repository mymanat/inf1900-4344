//
// Created by simon on 4/9/19.
//

#ifndef MAIN_SECTION4_H
#define MAIN_SECTION4_H


#include "Robot1.h"

/**
 * 0: Suivre ligne jusqu'à la ligne perpendiculaire
 * 1: Sur la ligne perpendiculaire jusqu'à dans la boîte
 * 2: Dans la boîte jusqu'à la ligne  perpendiculaire
 * 3: Dans la ligne perpediculaire jusqu'à ce que le robot trouve la ligne de trajectoire
 *
 * 4: Suivre ligne jusqu'à la ligne perpendiculaire
 * 5: Sur la ligne perpendiculaire jusqu'à dans la boîte
 * 6: Dans la boîte jusqu'à la ligne  perpendiculaire
 * 7: Dans la ligne perpediculaire jusqu'à ce que le robot trouve la ligne de trajectoire
 *
 * 8: Suivre ligne jusqu'à la ligne perpendiculaire
 * 9: Sur la ligne perpendiculaire jusqu'à dans la boîte
 * 10: Dans la boîte jusqu'à la ligne  perpendiculaire
 * 11: Dans la ligne perpediculaire jusqu'à ce que le robot trouve la ligne de trajectoire
 *
 */

class Section4 : public Robot1 {
public:
    Section4();

    bool evaluateState(uint8_t code) override;

    void evaluateAction(uint8_t code) override;

    void soundEnterBox();

    void soundExitBox();

private:
    uint16_t loopCount = 0;
};


#endif //MAIN_SECTION4_H
