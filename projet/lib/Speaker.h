#ifndef SPEAKER
#define SPEAKER

#include <avr/interrupt.h>

#include <avr/io.h>

#define F_CPU 8000000

#include "Utils.h"
#include "LED.h"
#include "Component.h"

/* On définit certaines notes de musique */

enum MusicNotes {
    MI4 = 64,
    MI3 = 52,
    RE = 62,
    FA4 = 65,
    FA3 = 53,
    DO = 60,
    SOL4 = 67,
    SOL3 = 55,
    SI = 59,
    LA = 57,
    LA4 = 69,
    LA5 = 81
};

class Speaker : public Component {
public:
    Speaker();

    void init() override;

    /**
     * Permet de jouer une mélodie avec des LEDs qui clignotes
     */
    void playSong();

    /**
     * Arrête tous les sons
     */
    void stopSound();


    /**
     * Joue une note
     * @param note
     */
    void playSound(MusicNotes note);

    void playFrequency();

    static void debugSound();


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