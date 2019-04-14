//
// Created by simon on 4/9/19.
//

#ifndef MAIN_SECTION2_H
#define MAIN_SECTION2_H


#include "Robot1.h"




class Section2 : public Robot1 {
public:

    Section2();

//ralentir dans demi lune pas reaccel
    bool evaluateState(uint8_t code) override;

    void evaluateAction(uint8_t code) override;

    void evaluateCurve(uint8_t code);

private:
    int16_t hitCount = 500;

};


#endif //MAIN_SECTION2_H
