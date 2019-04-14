/*
/ Created by Simon, Maxime, Simon and Samuel
/ Date : February 15, 2019
*/

#ifndef MAIN_BUTTON_H
#define MAIN_BUTTON_H


#include <avr/interrupt.h>
#include <util/delay.h>
#include "Component.h"


extern volatile uint8_t BTN_INT_STATE;


/**
 * Classe qui permet d'utiliser le bouton poussoir
 */
class Button : public Component {
public:
    /**
    / Default constructor of Button class.
    **/
    Button();

    /**
    / Initialisation routine for the button..
    **/
    void init() override;

    /**
    / Getter for the button state.
    **/
    bool getState() const;

    /**
    / Setter for the button state.
    **/
    static void setState(uint8_t state);
};


#endif //MAIN_BUTTON_H
