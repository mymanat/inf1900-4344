#include "speaker.h"

#define MI4 64
#define MI3 52
#define RE 62
#define FA4 65
#define FA3 53
#define DO 60
#define SOL4 67
#define SOL3 55
#define SI 59
#define LA 57
#define NOIRE 350

double Notes[37] = {110,    116.54, 123.47, 130.81, 138.59, 146.84, 155.56,
                    164.81, 174.61, 184.99, 195.99, 207.65, 220,    233.08,
                    246.94, 261.62, 277.18, 293.66, 311.12, 329.62, 349.22,
                    369.99, 391.99, 415.30, 440,    466.16, 493.88, 523.25,
                    554.36, 587.32, 622.25, 659.25, 698.45, 739.98, 783.99,
                    830.60, 880};

void jouerSon(int note) {
  arreterSon();
  _delay_ms(10);
  double freq = Notes[note - 45];

  double tempsCalcule = F_CPU * (1 / freq) / 2 / 256;

  OCR0A = tempsCalcule;

  // Mode 1 de Waveform Generation Mode, clear on compare match
  TCCR0A = (1 << WGM01) | (1 << COM0A0);

  // Prescaler 8
  TCCR0B = (1 << CS02);
  TCCR1C = 0;
}

void arreterSon() { TCCR0A = 0; }

void initialisationSpeaker(void) {
  cli();

  DDRB = 0xff;

  sei();
}

void jouerMelodie() {
  initialisationSpeaker();
  jouerSon(RE);
  _delay_ms(NOIRE / 8);
  jouerSon(MI4);
  _delay_ms(NOIRE / 2);
  jouerSon(FA4);
  _delay_ms(NOIRE / 2);
  jouerSon(FA4);
  _delay_ms(NOIRE / 2);
  jouerSon(MI4);
  _delay_ms(NOIRE / 8);
  jouerSon(MI4);
  _delay_ms(NOIRE / 8);
  jouerSon(FA4);
  _delay_ms(NOIRE / 8);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(DO);
  _delay_ms(NOIRE / 2);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(MI4);
  _delay_ms(NOIRE / 2);
  jouerSon(DO);
  _delay_ms(NOIRE / 8);
  jouerSon(SOL4);
  _delay_ms(NOIRE / 8);
  jouerSon(FA4);
  _delay_ms(NOIRE / 8);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(MI4);
  _delay_ms(NOIRE / 2);
  jouerSon(FA4);
  _delay_ms(NOIRE / 2);
  jouerSon(FA4);
  _delay_ms(NOIRE / 2);
  jouerSon(MI4);
  _delay_ms(NOIRE / 8);
  jouerSon(MI4);
  _delay_ms(NOIRE / 4);
  jouerSon(FA4);
  _delay_ms(NOIRE / 8);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(DO);
  _delay_ms(NOIRE / 2);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(MI4);
  _delay_ms(NOIRE / 2);
  jouerSon(DO);
  _delay_ms(NOIRE / 8);
  jouerSon(SOL4);
  _delay_ms(NOIRE / 8);
  jouerSon(FA4);
  _delay_ms(NOIRE / 8);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(DO);
  _delay_ms(NOIRE / 2);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);

  jouerSon(MI4);
  _delay_ms(NOIRE / 2);
  jouerSon(LA);
  _delay_ms(NOIRE / 2);
  jouerSon(LA);
  _delay_ms(NOIRE / 2);
  jouerSon(MI4);
  _delay_ms(NOIRE / 8);
  jouerSon(MI4);
  _delay_ms(NOIRE / 8);
  jouerSon(FA4);
  _delay_ms(NOIRE / 8);
  jouerSon(MI4);
  _delay_ms(NOIRE / 8);
  jouerSon(RE);
  _delay_ms(NOIRE / 8);
  jouerSon(SOL4);
  _delay_ms(NOIRE / 8);
  jouerSon(SI);
  _delay_ms(NOIRE / 8);
  jouerSon(RE);
  _delay_ms(NOIRE / 8);
  jouerSon(DO);
  _delay_ms(NOIRE / 8);

  jouerSon(FA4);
  _delay_ms(NOIRE / 2);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(DO);
  _delay_ms(NOIRE / 2);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(MI4);
  _delay_ms(NOIRE / 2);
  jouerSon(LA);
  _delay_ms(NOIRE / 2);
  jouerSon(LA);
  _delay_ms(NOIRE / 2);
  jouerSon(MI4);
  _delay_ms(NOIRE / 8);
  jouerSon(MI4);
  _delay_ms(NOIRE / 8);

  jouerSon(FA4);
  _delay_ms(NOIRE / 8);
  jouerSon(MI4);
  _delay_ms(NOIRE / 8);
  jouerSon(RE);
  _delay_ms(NOIRE / 8);
  jouerSon(SOL4);
  _delay_ms(NOIRE / 8);
  jouerSon(SI);
  _delay_ms(NOIRE / 8);
  jouerSon(RE);
  _delay_ms(NOIRE / 8);
  jouerSon(DO);
  _delay_ms(NOIRE / 8);
  jouerSon(FA4);
  _delay_ms(NOIRE / 2);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(MI4);
  _delay_ms(NOIRE / 2);
  jouerSon(FA4);
  _delay_ms(NOIRE / 2);
  jouerSon(FA4);
  _delay_ms(NOIRE / 2);

  jouerSon(MI4);
  _delay_ms(NOIRE / 8);
  jouerSon(MI4);
  _delay_ms(NOIRE / 8);
  jouerSon(FA4);
  _delay_ms(NOIRE / 8);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(DO);
  _delay_ms(NOIRE / 2);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(MI4);
  _delay_ms(NOIRE / 2);
  jouerSon(DO);
  _delay_ms(NOIRE / 8);
  jouerSon(SOL4);
  _delay_ms(NOIRE / 8);
  jouerSon(FA4);
  _delay_ms(NOIRE / 8);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);

  jouerSon(MI4);
  _delay_ms(NOIRE / 2);
  jouerSon(FA4);
  _delay_ms(NOIRE / 2);
  jouerSon(FA4);
  _delay_ms(NOIRE / 2);
  jouerSon(MI4);
  _delay_ms(NOIRE / 8);
  jouerSon(MI4);
  _delay_ms(NOIRE / 8);
  jouerSon(FA4);
  _delay_ms(NOIRE / 8);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(DO);
  _delay_ms(NOIRE / 2);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);

  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(MI4);
  _delay_ms(NOIRE / 2);
  jouerSon(DO);
  _delay_ms(NOIRE / 8);
  jouerSon(SOL4);
  _delay_ms(NOIRE / 8);
  jouerSon(FA4);
  _delay_ms(NOIRE / 8);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(DO);
  _delay_ms(NOIRE / 2);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(MI4);
  _delay_ms(NOIRE / 2);
  jouerSon(LA);
  _delay_ms(NOIRE / 2);

  jouerSon(LA);
  _delay_ms(NOIRE / 2);
  jouerSon(MI4);
  _delay_ms(NOIRE / 8);
  jouerSon(MI4);
  _delay_ms(NOIRE / 8);
  jouerSon(FA4);
  _delay_ms(NOIRE / 8);
  jouerSon(MI4);
  _delay_ms(NOIRE / 8);
  jouerSon(RE);
  _delay_ms(NOIRE / 8);
  jouerSon(SOL4);
  _delay_ms(NOIRE / 8);
  jouerSon(SI);
  _delay_ms(NOIRE / 8);
  jouerSon(RE);
  _delay_ms(NOIRE / 8);
  jouerSon(DO);
  _delay_ms(NOIRE / 8);
  jouerSon(FA4);
  _delay_ms(NOIRE / 2);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(DO);
  _delay_ms(NOIRE / 2);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);

  jouerSon(MI4);
  _delay_ms(NOIRE / 2);
  jouerSon(LA);
  _delay_ms(NOIRE / 2);
  jouerSon(LA);
  _delay_ms(NOIRE / 2);
  jouerSon(MI4);
  _delay_ms(NOIRE / 8);
  jouerSon(MI4);
  _delay_ms(NOIRE / 8);
  jouerSon(FA4);
  _delay_ms(NOIRE / 8);
  jouerSon(MI4);
  _delay_ms(NOIRE / 8);
  jouerSon(RE);
  _delay_ms(NOIRE / 8);
  jouerSon(SOL4);
  _delay_ms(NOIRE / 8);
  jouerSon(SI);
  _delay_ms(NOIRE / 8);
  jouerSon(RE);
  _delay_ms(NOIRE / 8);
  jouerSon(SOL4);
  _delay_ms(NOIRE / 8);
  jouerSon(FA4);
  _delay_ms(NOIRE / 8);
  arreterSon();
}

void jouerMelodie2() {
  initialisationSpeaker();
  jouerSon(LA);
  _delay_ms(NOIRE / 4);
  jouerSon(MI3);
  _delay_ms(NOIRE / 4);
  jouerSon(LA);
  _delay_ms(NOIRE / 4);
  jouerSon(MI4);
  _delay_ms(NOIRE / 4);
  jouerSon(RE);
  _delay_ms(NOIRE / 4);
  jouerSon(DO);
  _delay_ms(NOIRE / 4);
  jouerSon(SOL3);
  _delay_ms(NOIRE / 2);
  jouerSon(LA);
  _delay_ms(NOIRE / 4);
  jouerSon(MI3);
  _delay_ms(NOIRE / 4);
  jouerSon(LA);
  _delay_ms(NOIRE / 4);
  jouerSon(MI4);
  _delay_ms(NOIRE / 4);
  jouerSon(RE);
  _delay_ms(NOIRE / 4);
  jouerSon(DO);
  _delay_ms(NOIRE / 4);
  jouerSon(SOL3);
  _delay_ms(NOIRE / 2);

  jouerSon(DO);
  _delay_ms(NOIRE / 4);
  jouerSon(SI);
  _delay_ms(NOIRE / 4);
  jouerSon(SOL3);
  _delay_ms(NOIRE / 4);
  jouerSon(DO);
  _delay_ms(NOIRE / 2);
  jouerSon(SI);
  _delay_ms(NOIRE / 4);
  jouerSon(SOL3);
  _delay_ms(NOIRE / 2);
  jouerSon(DO);
  _delay_ms(NOIRE / 4);
  jouerSon(SI);
  _delay_ms(NOIRE / 4);
  jouerSon(SOL3);
  _delay_ms(NOIRE / 4);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(SI);
  _delay_ms(NOIRE / 4);
  jouerSon(SOL3);
  _delay_ms(NOIRE / 2);

  jouerSon(LA);
  _delay_ms(NOIRE / 4);
  jouerSon(MI3);
  _delay_ms(NOIRE / 4);
  jouerSon(LA);
  _delay_ms(NOIRE / 4);
  jouerSon(MI4);
  _delay_ms(NOIRE / 4);
  jouerSon(RE);
  _delay_ms(NOIRE / 4);
  jouerSon(DO);
  _delay_ms(NOIRE / 4);
  jouerSon(SOL3);
  _delay_ms(NOIRE / 2);
  jouerSon(LA);
  _delay_ms(NOIRE / 4);
  jouerSon(MI3);
  _delay_ms(NOIRE / 4);
  jouerSon(LA);
  _delay_ms(NOIRE / 4);
  jouerSon(MI4);
  _delay_ms(NOIRE / 4);
  jouerSon(RE);
  _delay_ms(NOIRE / 4);
  jouerSon(DO);
  _delay_ms(NOIRE / 4);
  jouerSon(SOL3);
  _delay_ms(NOIRE / 2);

  jouerSon(DO);
  _delay_ms(NOIRE / 4);
  jouerSon(DO);
  _delay_ms(NOIRE / 2);
  jouerSon(DO);
  _delay_ms(NOIRE / 4);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(MI4);
  _delay_ms(NOIRE / 4);
  jouerSon(MI4);
  _delay_ms(NOIRE / 2);
  jouerSon(MI4);
  _delay_ms(NOIRE / 4);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  jouerSon(RE);
  _delay_ms(NOIRE / 2);
  arreterSon();
}