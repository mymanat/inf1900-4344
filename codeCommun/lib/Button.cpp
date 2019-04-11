//
// Created by simon on 4/1/19.
//

#include "Button.h"
#include "Utils.h"

volatile uint8_t BTN_INT_STATE = 0;



Button::Button() {
    init();
}



ISR(INT0_vect) {
    // Debounce
    _delay_ms(30);

    BTN_INT_STATE = static_cast<uint8_t>(BTN_PRESSED);

    EIFR |= (1 << INTF0);

}

bool Button::getState() const{
    return BTN_INT_STATE;
}

void Button::setState(uint8_t state) {
    BTN_INT_STATE = state;
}

void Button::init() {
    DDR_BTN_INTERRUPT = MODE_ENTREE;
    EICRA |= (1 << ISC00);
    setState(false);

}

