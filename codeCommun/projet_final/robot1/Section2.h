//
// Created by simon on 4/9/19.
//

#ifndef MAIN_SECTION2_H
#define MAIN_SECTION2_H


#include "Robot1.h"

#include <math.h>

/**
 * States:
 * 0: follow line until hard right turn
 * 1: hard right turn
 * 2:follow line
 * 4:end
 */

class Section2 : public Robot1 {
public:

    Section2();

//ralentir dans demi lune pas reaccel
    bool evaluateState(uint8_t code) override;

    void evaluateAction(uint8_t code) override;

    void evaluateCurve(uint8_t code);

private:


    int16_t min = 110;
    int16_t max = 200;
    int16_t hitCountMax = 8000;
    int16_t b = hitCountMax / 2;
    int16_t hitCount = b;

//    double a = pow(-1 * (min - max), 1 / (hitCountMax - 500));
    double a = 0;

};


#endif //MAIN_SECTION2_H
