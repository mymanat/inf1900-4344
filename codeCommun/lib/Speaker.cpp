#include "Speaker.h"

int NOIRE;

void Speaker::arreterSon() {
    TCCR0A = 0;
}

void Speaker::initialisationSpeaker(void) {
    cli();

    DDR_SPEAKER = MODE_OUTPUT;

    sei();
}

void Speaker::jouerSonDebugState(uint8_t state) {
    //0: C3
    uint8_t note = 0;
    switch (state)
    {
        case 0:
            note = MI3;
            break;
        case 1:
            note = FA3;
            break;
        case 2:
            note = SOL3;
            break;
        case 3:
            note = LA;
            break;
        case 4:
            note = SI;
            break;
        case 5:
            note = DO;
            break;
    }

    jouerSon(note);
    wait(200);
    arreterSon();
}

void Speaker::jouerSon(int note) {


    arreterSon();

    wait(10);

    double freq = Notes[note - 45];

    double tempsCalcule = F_CPU * (1 / freq) / 2 / 256;

    OCR0A = tempsCalcule;

    // Mode 1 de Waveform Generation Mode, clear on compare match

    TCCR0A = (1 << WGM01) | (1 << COM0A0);

    // Prescaler 256

    TCCR0B = (1 << CS02);

    TCCR1C = 0;
}

void Speaker::playFrequency() {

    arreterSon();

    wait(10);

    //        double freq = Notes[note - 45];
    double freq = 38100;

    double tempsCalcule = F_CPU * (1 / freq) / 2;

    OCR0A = tempsCalcule;

    // Mode 1 de Waveform Generation Mode, clear on compare match

    TCCR0A = (1 << WGM01) | (1 << COM0A0);

    // Prescaler 256

    //TCCR0B = (1 << CS01) | (1 << CS00);
    TCCR0B = (1 << CS00);
    //TCCR0B = (1 << CS02);

    TCCR1C = 0;
}


Speaker::Speaker() {
    initialisationSpeaker();
}


void Speaker::jouerMelodie() {
    LED del;

    NOIRE = 700;
    jouerSon(RE);
    del.turnOff();
    del.turnOn(1);

    wait(NOIRE / 8);

    jouerSon(MI4);
    del.turnOff();
    del.turnOn(2);

    wait(NOIRE / 2);

    jouerSon(FA4);
    del.turnOff();
    del.turnOn(3);

    wait(NOIRE / 2);

    jouerSon(FA4);
    del.turnOff();
    del.turnOn(3);

    wait(NOIRE / 2);

    jouerSon(MI4);
    del.turnOff();
    del.turnOn(2);

    wait(NOIRE / 8);

    jouerSon(MI4);
    del.turnOff();
    del.turnOn(2);

    wait(NOIRE / 8);

    jouerSon(FA4);
    del.turnOff();
    del.turnOn(3);

    wait(NOIRE / 8);

    jouerSon(RE);
    del.turnOff();
    del.turnOn(1);

    wait(NOIRE / 2);

    jouerSon(DO);
    del.turnOff();
    del.turnOn(4);

    wait(NOIRE / 2);

    jouerSon(RE);
    del.turnOff();
    del.turnOn(1);

    wait(NOIRE / 2);

    jouerSon(RE);
    del.turnOff();
    del.turnOn(1);

    wait(NOIRE / 2);

    jouerSon(MI4);
    del.turnOff();
    del.turnOn(2);

    wait(NOIRE / 2);

    jouerSon(DO);
    del.turnOff();
    del.turnOn(4);

    wait(NOIRE / 8);

    jouerSon(SOL4);

    wait(NOIRE / 8);

    jouerSon(FA4);
    del.turnOff();
    del.turnOn(3);

    wait(NOIRE / 8);

    jouerSon(RE);
    del.turnOff();
    del.turnOn(1);

    wait(NOIRE / 2);

    jouerSon(MI4);
    del.turnOff();
    del.turnOn(2);

    wait(NOIRE / 2);

    jouerSon(FA4);
    del.turnOff();
    del.turnOn(3);

    wait(NOIRE / 2);


    jouerSon(FA4);
    del.turnOff();
    del.turnOn(3);

    wait(NOIRE / 2);

    jouerSon(MI4);
    del.turnOff();
    del.turnOn(2);

    wait(NOIRE / 8);

    jouerSon(MI4);
    del.turnOff();
    del.turnOn(2);

    wait(NOIRE / 4);

    jouerSon(FA4);
    del.turnOff();
    del.turnOn(3);

    wait(NOIRE / 8);

    jouerSon(RE);
    del.turnOff();
    del.turnOn(1);

    wait(NOIRE / 2);

    jouerSon(DO);
    del.turnOff();
    del.turnOn(4);

    wait(NOIRE / 2);
    arreterSon();
}