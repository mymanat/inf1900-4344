#include "moteurs.h"

void initialisationMoteurs(void) {
  cli();
  DDRD = 0xff;
  sei();
}

void ajustementPWM(int pa, int pb) {
  OCR1A = 255 * ((float)pa / 100);

  OCR1B = 255 * ((float)pb / 100);

  // Mode 1 de Waveform Generation Mode, clear on compare match
  TCCR1A = (1 << WGM10) | (1 << COM1B1) | (1 << COM1A1);

  // Prescaler 8
  TCCR1B = (1 << CS11);
  TCCR1C = 0;
}