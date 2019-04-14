//
// Created by simon on 4/9/19.
//

#ifndef MAIN_SECTION2_H
#define MAIN_SECTION2_H


#include "Robot1.h"

#include <math.h>

/**
 * Facteur de décélération lors des courbes
 */
#define SECTION2_DECEL_FACTOR 15


/**
 *
 * On utilise la formule suivante pour déterminer la vitesse du robot:
 * v=-0.00036*(x-500)^2+200
 * où x correspond au nombre de fois que le robot à dû tourner
 *
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
    int16_t hitCountHalf = hitCountMax / 2;
    int16_t hitCount = hitCountHalf;

    double a = (min - max) / pow(hitCountHalf, 2);

};


#endif //MAIN_SECTION2_H
