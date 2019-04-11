//
// Created by simon on 4/9/19.
//

#ifndef MAIN_SECTION1_H
#define MAIN_SECTION1_H


#include "Robot1.h"

/*  State 0 : SuivreLigne
    State 1 : tourner gauche
    State 2 : 
*/
class Section1 : public Robot1 {
public:
    bool evaluateState(uint8_t code) override;

    void evaluateAction(uint8_t code) override;
};


#endif //MAIN_SECTION1_H
