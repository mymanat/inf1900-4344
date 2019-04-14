//
// Created by Simon Tran
//

#ifndef MAIN_TIMER_H
#define MAIN_TIMER_H

#include <avr/interrupt.h>
#include "Component.h"

/**
 * La durée d'une seconde en fonction du prescaler
 */
#define TIMER_1S_DURATION 7812


extern volatile uint8_t TIMER1_DONE;


/**
 * Classe permettant de définir un compteur de 0 jusqu'à duration.
 */
class Timer : public Component {

public:
    Timer();

    void init() override;

    /**
     * Démarre le compteur
     */
    void startTimer();


    /**
     * Permet de savoir si le compteur a terminé
     * @return Si le compteur a terminé
     */
    bool isDone();


    /**
     * Permet de définir la durée du compteur en secondes
     * @param durationSec Nombre de secondes
     */
    void setDurationSec(uint16_t durationSec);


    /**
     * Retourne la valeur du registre du compteur
     * @return La valeur du compteur
     */
    uint16_t getValue();


    /* Getters & Setters */

    void setDuration(uint16_t duration);

    uint16_t getDuration() const;

private:

    uint16_t duration;


};


#endif //MAIN_TIMER_H
