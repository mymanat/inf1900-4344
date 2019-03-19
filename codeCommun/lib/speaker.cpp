#include "speaker.h"

double Notes[36] = {110,    116.54, 123.47, 130.81, 138.59, 146.84,
                    155.56, 164.81, 174.61, 184.99, 195.99, 207.65,
                    220,    233.08, 246.94, 261.62, 277.18};

void jouerSon(int note) {
  double freq = Notes[note - 45];

  double tempsCalcule = 8000000 * (1 / freq) / 2 / 64;

  OCR0A = tempsCalcule;

  // Mode 1 de Waveform Generation Mode, clear on compare match
  TCCR0A = (1 << WGM01) | (1 << COM0A0);

  // Prescaler 8
  TCCR0B = (1 << CS01) | (1 << CS00);
  TCCR1C = 0;
}

void arreterSon() { OCR0A = 0; }

void initialisationSpeaker(void) {
  cli();

  DDRB = 0xff;

  sei();
}