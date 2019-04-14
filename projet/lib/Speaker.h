#ifndef SPEAKER
#define SPEAKER

#include <avr/interrupt.h>

#include <avr/io.h>

#define F_CPU 8000000

#include "Utils.h"
#include "wait.h"
#include "LED.h"

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

#define LA4 69
#define LA5 81

class Speaker {
public:
    Speaker();

    void jouerSonDebugState(uint8_t state);

    void jouerMelodie();



    void arreterSon();

    void initialisationSpeaker(void);

    void jouerSon(int note);

    void playFrequency();

    static void debugSound(){
        Speaker speaker;
        speaker.jouerSon(80);
        wait(40);
        speaker.jouerSon(70);
        wait(40);
        speaker.arreterSon();
    }

    double Notes[37] = {
            110,            //A2
            116.54, 123.47, //B2
            130.81,         //C3
            138.59, 146.84, //D3
            155.56,

            164.81,         //E3
            174.61,         //F3
            184.99, 195.99, //G3
            207.65, 220,    //A3
            233.08,

            246.94, //B3
            261.62, //C4
            277.18, 293.66,//D4
            311.12, 329.62, //E4
            349.22, //F4

            369.99, 391.99,//G4
            415.30, 440, //A4
            466.16, 493.88,//B4
            523.25,//C5

            554.36, 587.32, 622.25,
            659.25, 698.45,
            739.98, 783.99,//G5

            830.60, 880 //A5
    };
};

#endif