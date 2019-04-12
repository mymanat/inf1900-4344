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

    bool followLine(char code);

/**
 * Suivre ligne
 * @param code
 * @param speed Vitesse des roues par defaut
 * @param slowWheelSpeed Vitesse de la roue plus lente (pour tourner)
 * @return
 */
    bool followLine(char code, uint8_t speed, uint8_t slowWheelSpeed);


/**
 * Le robot va suivre la ligne jusqu´au virage à gauche. Il va effectuer ce virage de 90 degrés et s'arrêter
 */
    void transitionState();

    uint8_t receiveData();

    // Getters & Setters

    uint8_t getSpeed() const;

    void setSpeed(uint8_t speed);

    bool isShouldGoStraight() const;

    void setShouldGoStraight(bool shouldGoStraight);


    //todo Remvoe
    static void changeStateSound() {
        Speaker speaker;
        speaker.jouerSon(80);
        wait(100);
        speaker.arreterSon();
        wait(20);
        speaker.jouerSon(70);
        wait(100);
        speaker.arreterSon();
        speaker.jouerSon(70);
        wait(100);
        speaker.arreterSon();
    }

    uint8_t getTurnSpeed() const;

    void setTurnSpeed(uint8_t turnSpeed);


protected:


    LED led;
    Timer timer;
    Motors motor;
    TrackerSensor trackerSensor;
    Button button;
    Speaker speaker;

    uint8_t state = 0;

private:

    /**
     * Défini si le robot devrait aller tout droit lorsque les capteurs ne détectent rien
     */
    bool shouldGoStraight = false;

    uint8_t speed = MOTOR_MAX_SPEED;
    uint8_t turnSpeed = speed / 2;





};

#endif //MAIN_ROBOT1_H
