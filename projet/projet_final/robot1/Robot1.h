//
// Created by simon tran on 4/3/19.
//

#ifndef MAIN_ROBOT1_H
#define MAIN_ROBOT1_H

#include "Utils.h"

#include "Timer.h"
#include "Button.h"

#include "LED.h"
#include "Motors.h"
#include "TrackerSensor.h"

#include "Speaker.h"

#include "IRTransceiver.h"

/**
 * Classe qui contient les méthodes utiles à l'exécution du parcourt. Les 4 classes de section héritent de celle-ci.
 *
 * Elle possède la boucle d'exécution dans la méthode "run()". Celle-ci met à jours les capteurs et les DELs.
 * Ensuite, elle appelle la méthode evaluateAction(), puis evaluateState();
 */
class Robot1 {
public:


    /**
     * Retourne la valeur reçue soit par code infrarouge où à l'aide du bouton poussoir
     * @return La valeur
     */
    static uint8_t receiveData();


    /**
     * Démarre la boucle principale d'actions. Cette méthode appelle les méthodes virtuelles "evaluateAction()" et "evaluateStat()".
     *
     */
    virtual void run();

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

    /**
     * Simple algorithme permettant de suivre une ligne
     * @param code Code binaire représentant l'état des capteurs
     * @return Vrai si le capteur n'observe aucune ligne
     */
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



    // Getters & Setters

    uint8_t getSpeed() const;

    void setSpeed(uint8_t speed);

    bool isShouldGoStraight() const;

    void setShouldGoStraight(bool shouldGoStraight);


    bool isShouldTransition() const;

    void setShouldTransition(bool shouldTransition);

protected:
    LED led;
    Timer timer;
    Motors motor;
    TrackerSensor trackerSensor;
    Button button;
    Speaker speaker;

    /**
     * Définie l'état de la machine à état
     */
    uint8_t state = 0;

private:
/**
 * Défini si le robot devrait aller tout droit lorsque les capteurs ne détectent rien
 */
    bool shouldGoStraight = false;

    /**
     * Défini si le robot devrait effectuer une rotation de 90 degrés lors de la transition
     */
    bool shouldTurnAfterTransition = true;

    uint8_t speed = MOTOR_FAST_SPEED;
};

#endif //MAIN_ROBOT1_H
