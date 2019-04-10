//
// Created by simon on 4/9/19.
//

#ifndef MAIN_SECTION4_H
#define MAIN_SECTION4_H


#include "Robot1.h"

class Section4 : public Robot1 {
public:
    bool evaluateState(uint8_t code) override;

    void evaluateAction(uint8_t code) override;

};


#endif //MAIN_SECTION4_H
