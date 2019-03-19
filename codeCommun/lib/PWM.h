//
// Created by simon on 3/18/19.
//

#ifndef LIB_PWM_H
#define LIB_PWM_H
#include <avr/interrupt.h>

#include "constantes.h"


class PWM {

public:
    void ajustementPWM(float pa, float pb) const;
    PWM();
};


#endif //LIB_PWM_H
