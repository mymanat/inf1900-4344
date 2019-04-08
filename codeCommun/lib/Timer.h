//
// Created by simon on 4/1/19.
//

#ifndef MAIN_TIMER_H
#define MAIN_TIMER_H

#include <avr/interrupt.h>
#include "Component.h"

#define DUREE_1S 7812


extern volatile uint8_t TIMER1_DONE ;


/**
 * Classe permettant de définir un compteur de 0 jusqu'à duration.
 */
class Timer : public Component {

public:
    Timer();

    void init() override;
    Timer(uint16_t duration);

    void startTimer();

    uint16_t getDuration() const;

    void setDurationSec(uint16_t durationSec);
    void setDuration(uint16_t duration);
    uint16_t getValue();
    bool isDone();






private:

    uint16_t duration;




};






#endif //MAIN_TIMER_H
