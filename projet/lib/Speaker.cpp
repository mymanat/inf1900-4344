#include "Speaker.h"

/**
 * Représente la durée d'une noire ou d'un battement de la mélodie
 */
int NOIRE;

void Speaker::stopSound() {
    TCCR0A = 0;
}


void Speaker::debugSound() {
    Speaker speaker;
    speaker.playSound(LA5);
    wait(40);
    speaker.playSound(SOL4);
    wait(40);
    speaker.stopSound();
}


void Speaker::playSound(MusicNotes note) {


    stopSound();

    wait(10);

    double freq = Notes[note - 45];

    double calculatedTime = F_CPU * (1 / freq) / 2 / 256;

    OCR0A = calculatedTime;

    // Mode 1 de Waveform Generation Mode, clear on compare match

    TCCR0A = (1 << WGM01) | (1 << COM0A0);

    // Prescaler 256

    TCCR0B = (1 << CS02);

    TCCR1C = 0;
}

void Speaker::playFrequency() {

    stopSound();

    wait(10);

    //        double freq = Notes[note - 45];
    double freq = 38100;

    double calculatedTime = F_CPU * (1 / freq) / 2;

    OCR0A = calculatedTime;

    // Mode 1 de Waveform Generation Mode, clear on compare match

    TCCR0A = (1 << WGM01) | (1 << COM0A0);

    // Prescaler 256

    //TCCR0B = (1 << CS01) | (1 << CS00);
    TCCR0B = (1 << CS00);
    //TCCR0B = (1 << CS02);

    TCCR1C = 0;
}


Speaker::Speaker() {
    init();
}

void Speaker::init() {
    cli();
    DDR_SPEAKER = MODE_OUTPUT;
    sei();

}

void Speaker::playSong() {
    LED del;

    NOIRE = 700;
    playSound(RE);
    del.turnOff();
    del.turnOn(1);

    wait(NOIRE / 8);

    playSound(MI4);
    del.turnOff();
    del.turnOn(2);

    wait(NOIRE / 2);

    playSound(FA4);
    del.turnOff();
    del.turnOn(3);

    wait(NOIRE / 2);

    playSound(FA4);
    del.turnOff();
    del.turnOn(3);

    wait(NOIRE / 2);

    playSound(MI4);
    del.turnOff();
    del.turnOn(2);

    wait(NOIRE / 8);

    playSound(MI4);
    del.turnOff();
    del.turnOn(2);

    wait(NOIRE / 8);

    playSound(FA4);
    del.turnOff();
    del.turnOn(3);

    wait(NOIRE / 8);

    playSound(RE);
    del.turnOff();
    del.turnOn(1);

    wait(NOIRE / 2);

    playSound(DO);
    del.turnOff();
    del.turnOn(4);

    wait(NOIRE / 2);

    playSound(RE);
    del.turnOff();
    del.turnOn(1);

    wait(NOIRE / 2);

    playSound(RE);
    del.turnOff();
    del.turnOn(1);

    wait(NOIRE / 2);

    playSound(MI4);
    del.turnOff();
    del.turnOn(2);

    wait(NOIRE / 2);

    playSound(DO);
    del.turnOff();
    del.turnOn(4);

    wait(NOIRE / 8);

    playSound(SOL4);

    wait(NOIRE / 8);

    playSound(FA4);
    del.turnOff();
    del.turnOn(3);

    wait(NOIRE / 8);

    playSound(RE);
    del.turnOff();
    del.turnOn(1);

    wait(NOIRE / 2);

    playSound(MI4);
    del.turnOff();
    del.turnOn(2);

    wait(NOIRE / 2);

    playSound(FA4);
    del.turnOff();
    del.turnOn(3);

    wait(NOIRE / 2);


    playSound(FA4);
    del.turnOff();
    del.turnOn(3);

    wait(NOIRE / 2);

    playSound(MI4);
    del.turnOff();
    del.turnOn(2);

    wait(NOIRE / 8);

    playSound(MI4);
    del.turnOff();
    del.turnOn(2);

    wait(NOIRE / 4);

    playSound(FA4);
    del.turnOff();
    del.turnOn(3);

    wait(NOIRE / 8);

    playSound(RE);
    del.turnOff();
    del.turnOn(1);

    wait(NOIRE / 2);

    playSound(DO);
    del.turnOff();
    del.turnOn(4);

    wait(NOIRE / 2);
    stopSound();
}


