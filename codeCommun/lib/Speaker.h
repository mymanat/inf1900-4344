#ifndef SPEAKER
#define SPEAKER


#include <avr/interrupt.h>
#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>
#include "constantes.h"


class Speaker{
public:
    Speaker();
    void arreterSon();
    void initialisationSpeaker(void);
    void jouerSon(int note);
    double trouverFrequence(int note);

    double Notes[36] = {110,    116.54, 123.47, 130.81, 138.59, 146.84,
                        155.56, 164.81, 174.61, 184.99, 195.99, 207.65,
                        220,    233.08, 246.94, 261.62, 277.18};
};

#endif