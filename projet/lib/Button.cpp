/*Class that represent a button.
/ Created by Simon, Maxime, Simon and Samuel
/ Date : February 15, 2019
*/

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
    DDR_INT_BTN = MODE_INPUT;
    EICRA |= (1 << ISC00);
    setState(false);

}

