/*
/ Created by Simon, Maxime, Simon and Samuel
/ Date : February 15, 2019
*/

#ifndef MAIN_LED_H
#define MAIN_LED_H

#include "Utils.h"

#define LED_ONBOARD_OFF 0
#define LED_ONBOARD_GREEN 1
#define LED_ONBOARD_RED 2


/**
 * Classe Permettant de contrôler les DELs.
 * La DEL doit être connectée au PORTC
 */
class LED {


public:
    LED();

    /**
     * Permet d'obtenir la position d'une DEL en fonction de son numéro
     * @param numLED Numéro (1 à 5)
     * @return Position sur le PORTC (0 à 7)
     */
    uint8_t getLEDPosition(uint8_t numLED) const;

/**
 * Permet d'allumer en rouge la DEL avec un index
 * @param numLED Le numero de la DEL à allumer (1 à 5)
 */
    void turnOn(uint8_t numLED) const;

    /**
     * Allume toutes les DEL
     */
    void turnOn() const;

    /**
     * Éteint une DEL
     * @param numLED Numero de la DEL
     */
    void turnOff(uint8_t numLED) const;

/**
 * Permet d'éteindre toutes les DELs
 */
    void turnOff() const;


/**
 * Permet de définir l'état de toutes les DELs
 * @param state l'état
 */
    void setState(bool state) const;

    /**
     * Permet de définir l'état d'une DEL
     * @param state L'état
     * @param numLED Le numéro de la DEL
     */
    void setState(bool state, uint8_t numLED) const;


    /**
     * Permet de définir l'état de la DEL sur la carte mère
     *
     * @param state L'état de la DEL. 0: éteinte, 1: Vert, 2: Rouge
     */
    void setStateOnboardLED(uint8_t state) const;

};


#endif //MAIN_LED_H
