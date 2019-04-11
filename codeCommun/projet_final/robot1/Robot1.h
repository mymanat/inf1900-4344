//
// Created by simon on 4/3/19.
//

#ifndef MAIN_ROBOT1_H
#define MAIN_ROBOT1_H

#include "../Robot.h"
#include "DEL.h"
#include "moteurs.h"
#include "TrackerSensor.h"


#include "Speaker.h"

#include "IRTransceiver.h"


//todo
#include "../../lib/DEL.h"
#include "../../lib/Timer.h"
#include "../../lib/moteurs.h"
#include "../../lib/TrackerSensor.h"
#include "../../lib/Button.h"
#include "../../lib/Speaker.h"
#include "../../lib/IRTransceiver.h"


//#define VITESSE_MAX 200
//#define VITESSE_LENT 150
#define DELTA_V 20


class Robot1 : public Robot {
public:

    Robot1();

    void init() override;


    void run() override;


    virtual bool evaluateState(uint8_t code);

    virtual void evaluateAction(uint8_t code);


    bool suivreLigne(char code);

    bool suivreLigne(char code, uint8_t speed, uint8_t slowWheelSpeed);

    void transitionState();


    uint8_t receiveData();


    // Getters & Setters


    uint8_t getVitesse() const;

    void setVitesse(uint8_t vitesse);

    bool isShouldGoStraight() const;

    void setShouldGoStraight(bool shouldGoStraight);


    //todo Remvoe
    void changeStateSound() {
        speaker.jouerSon(80);
        wait(50);
        speaker.arreterSon();
        wait(20);
        speaker.jouerSon(70);
        wait(50);
        speaker.arreterSon();
    }


protected:


    DEL del;
    Timer timer;
    moteurs moteur;
    TrackerSensor trackerSensor;
    Button button;
    Speaker speaker;


    uint8_t state = 0;

private:

    /**
     * Défini si le robot devrait aller tout droit lorsque les capteurs ne détectent rien
     */
    bool shouldGoStraight = false;

    uint8_t vitesse = VITESSE_MAX;


};


#endif //MAIN_ROBOT1_H
