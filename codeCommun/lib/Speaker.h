#ifndef SPEAKER
#define SPEAKER


#include <avr/interrupt.h>

#include <avr/io.h>

#define F_CPU 8000000

#include <util/delay.h>


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

class Speaker {
public:

    Speaker();

    void jouerMelodie();

    void jouerMelodie2();

    void arreterSon();

    void initialisationSpeaker(void);

    void jouerSon(int note);

    double trouverFrequence(int note);


    double Notes[37] = {110, 116.54, 123.47, 130.81, 138.59, 146.84, 155.56,

                        164.81, 174.61, 184.99, 195.99, 207.65, 220, 233.08,

                        246.94, 261.62, 277.18, 293.66, 311.12, 329.62, 349.22,

                        369.99, 391.99, 415.30, 440, 466.16, 493.88, 523.25,

                        554.36, 587.32, 622.25, 659.25, 698.45, 739.98, 783.99,

                        830.60, 880};
};


#endif