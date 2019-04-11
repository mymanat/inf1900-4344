//
// Created by simon on 3/18/19.
//

#ifndef MAIN_LED_H
#define MAIN_LED_H

#include "Utils.h"


/**
 * Classe Permettant de contrôler la DEL.
 * Celle-ci doit être branchée sur le PORTC (comme défini dans constantes.h), avec le + connecté au bit 1, et le - au bit 2 (pour la première DEL)
 */
class LED {


public:
    LED();

    uint8_t getLEDPosition(uint8_t numLED) const;

/**
 * Permet d'allumer en rouge la DEL branchée sur la pin "numeroDEL" du PORTA
 * @param numLED Le numero de la DEL à allumer
 */
    void turnOn(uint8_t numLED) const;

    void turnOn() const;

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

};


#endif //MAIN_LED_H
