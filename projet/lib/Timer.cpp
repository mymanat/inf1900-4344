//
// Created by simon on 4/1/19.
//

#include "Timer.h"

volatile uint8_t TIMER1_DONE;


Timer::Timer() {
    init();

}

void Timer::init() {
    // cli est une routine qui bloque toutes les interruptions.
    // Il serait bien mauvais d'être interrompu alors que
    // le microcontroleur n'est pas prêt...

    cli();
    TIMER1_DONE = 0;

    // cette procédure ajuste le registre EIMSK
    // de l’ATmega324PA pour permettre les interruptions externes


    EIMSK |= (1 << INT0);
    TCCR1B = (1 << CS12) | (1 << CS10);

    // sei permet de recevoir à nouveau des interruptions.

    sei();
}

void Timer::startTimer() {

    //TODO
    // mode CTC du timer 1 avec horloge divisée par 1024
    // interruption après la durée spécifiée

    TIMER1_DONE = 0;
    TCNT1 = 0;

    OCR1A = duration;

    TCCR1A = (1 << WGM12);

    TCCR1B = (1 << CS12) | (1 << CS10);

    TCCR1C = 0;

    TIMSK1 = (1 << OCIE1A);


}


uint16_t Timer::getDuration() const {
    return duration;
}

void Timer::setDuration(uint16_t duration) {
    Timer::duration = duration;
}

void Timer::setDurationSec(uint16_t durationSec) {
    setDuration(durationSec * TIMER_1S_DURATION);
}

uint16_t Timer::getValue() {
    return TCNT1;
}

bool Timer::isDone() {
    return TIMER1_DONE;
}

ISR(TIMER1_COMPA_vect) {
    TIMER1_DONE = 1;
}