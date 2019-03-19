#include <avr/interrupt.h>
#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>

void jouerMelodie();
void jouerMelodie2();
void arreterSon();
void initialisationSpeaker(void);
void jouerSon(int note);
double trouverFrequence(int note);