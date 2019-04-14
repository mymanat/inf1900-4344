//
// Simon Tran
//

#ifndef MAIN_BUTTON_H
#define MAIN_BUTTON_H


#include <avr/interrupt.h>
#include <util/delay.h>
#include "Component.h"


extern volatile uint8_t BTN_INT_STATE;


class Button : public Component {
public:
    Button();

    void init() override;

    bool getState() const;

    static void setState(uint8_t state);


private:

};


#endif //MAIN_BUTTON_H
