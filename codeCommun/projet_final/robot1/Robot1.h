//
// Created by simon on 4/3/19.
//

#ifndef MAIN_ROBOT1_H
#define MAIN_ROBOT1_H

#include "../Robot.h"
#include "LED.h"
#include "Motors.h"
#include "TrackerSensor.h"

#include "Speaker.h"

#include "IRTransceiver.h"

//todo
#include "../../lib/LED.h"
#include "../../lib/Timer.h"
#include "../../lib/Motors.h"
#include "../../lib/TrackerSensor.h"
#include "../../lib/Button.h"
#include "../../lib/Speaker.h"
#include "../../lib/IRTransceiver.h"

#define DELTA_V 20


class Robot1 : public Robot {
public:

    Robot1();

    void init() override;


    void run() override;


    virtual bool evaluateState(uint8_t code);

    virtual void evaluateAction(uint8_t code);

    bool suivreLigne(char code);

/**
 * Suivre ligne
 * @param code
 * @param speed Vitesse des roues par defaut
 * @param slowWheelSpeed Vitesse de la roue plus lente (pour tourner)
 * @return
 */
    bool suivreLigne(char code, uint8_t speed, uint8_t slowWheelSpeed);

/**
 * Le robot va suivre la ligne jusqu´au virage à gauche. Il va effectuer ce virage de 90 degrés et s'arrêter
 */
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


    LED del;
    Timer timer;
    Motors moteur;
    TrackerSensor trackerSensor;
    Button button;
    Speaker speaker;

    uint8_t state = 0;

private:

    /**
     * Défini si le robot devrait aller tout droit lorsque les capteurs ne détectent rien
     */
    bool shouldGoStraight = false;

    uint8_t vitesse = MOTOR_MAX_SPEED;


};

#endif //MAIN_ROBOT1_H
