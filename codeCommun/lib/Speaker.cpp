#include "Speaker.h"


Speaker::Speaker() {
    cli();

    DDR_SPEAKER = 0xff;

    sei();
}

void Speaker::arreterSon() {
    OCR0A = 0;
}


void Speaker::jouerSon(int note) {
    double freq = Notes[note - 45];

    double tempsCalcule = 8000000 * (1 / freq) / 2 / 64;

    OCR0A = tempsCalcule;

    // Mode 1 de Waveform Generation Mode, clear on compare match
    TCCR0A = (1 << WGM01) | (1 << COM0A0);

    // Prescaler 8
    TCCR0B = (1 << CS01) | (1 << CS00);
    TCCR1C = 0;
}

double Speaker::trouverFrequence(int note) {
    //todo?
}
