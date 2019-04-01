//
// Created by simon on 4/1/19.
//

#ifndef MAIN_BUTTON_H
#define MAIN_BUTTON_H


#include <avr/interrupt.h>
#include <util/delay.h>

#define BTN_PRESSED PIND & 0x04

extern volatile uint8_t BTN_INT_STATE ;


class Button {
public:
    Button();

    bool getState() const;
    void setState(bool state);

private:


};






#endif //MAIN_BUTTON_H
