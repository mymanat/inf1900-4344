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


class Robot1 : public Robot {
public:
    Robot1();

    void init() override;

    void run() override;

    /**
     * Permet d'évaluer si un changement d'état est nécessaire dans la machine à état
     * @param code Code binaire représentant l'état des capteurs
     * @return Vrai si on doit rester dans la boucle principale. Faux permet de faire la transition vers la section suivante
     */
    virtual bool evaluateState(uint8_t code);

    /**
     * Permet d'évaluer l'action à effectuer en fonction de l'état
     * @param code Code binaire représentant l'état des capteurs
     */
    virtual void evaluateAction(uint8_t code);

    bool followLine(char code);

    /**
 * Suivre ligne
 * @param code
 * @param speed Vitesse des roues par defaut
 * @param slowWheelSpeed Vitesse de la roue plus lente (pour tourner)
 * @return Si il détecte au moins une ligne noir
 */
    bool followLine(char code, uint8_t speed, uint8_t slowWheelSpeed);

    /**
 * Le robot va suivre la ligne jusqu´au virage à gauche. Il va effectuer ce virage de 90 degrés et s'arrêter
 */
    void transitionState();

    static uint8_t receiveData();

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

    static void changeSectionSound() {
        Speaker speaker;
        speaker.jouerSon(70);
        wait(100);
        speaker.arreterSon();
        wait(20);
        speaker.jouerSon(80);
        wait(100);
        speaker.arreterSon();
        speaker.jouerSon(70);
        wait(100);
        speaker.arreterSon();
        speaker.jouerSon(70);
        wait(100);
        speaker.arreterSon();
        wait(20);
        speaker.jouerSon(80);
        wait(100);
        speaker.arreterSon();
        speaker.jouerSon(70);
        wait(100);
        speaker.arreterSon();
    }

    bool isShouldTransition() const;

    void setShouldTransition(bool shouldTransition);

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

    bool shouldTurnAfterTransition = true;

    uint8_t speed = MOTOR_FAST_SPEED;
};

#endif //MAIN_ROBOT1_H
