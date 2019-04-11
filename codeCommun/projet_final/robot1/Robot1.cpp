//
// Created by simon on 4/3/19.
//

#include "Robot1.h"


Robot1::Robot1() {
    init();
}

void Robot1::init() {

}

void Robot1::transitionState() {
    state = 0;
    uint8_t code = 0;
    do
    {

        trackerSensor.update();
        code = trackerSensor.getSensorStateCode();
        if (state == 0)
        {
            /* Suit la ligne jusqu'au virage */
            suivreLigne(code);
            if (compareBits(code, "00xx1"))
            {
                state++;
            }
        }
        else
        {
            /* Virage */
            moteur.adjust(0, MOTOR_SLOW_SPEED);
            if (compareBits(code, "00100"))
            {
                state++;
            }
        }


    } while (state < 3);
    moteur.stop();
}

void Robot1::run() {
    moteur.init();
    trackerSensor.init();
    bool shouldLoop = true;
    while (shouldLoop)
    {

        trackerSensor.update();


        evaluateAction(trackerSensor.getSensorStateCode());
        shouldLoop = evaluateState(trackerSensor.getSensorStateCode());
    }

    transitionState();
}

bool Robot1::evaluateState(uint8_t code) {
    return true;
}

void Robot1::evaluateAction(uint8_t code) {
    suivreLigne(code);

}

bool Robot1::suivreLigne(char code, uint8_t speed, uint8_t slowWheelSpeed) {
    if (compareBits(code, "00xzz"))
    {
        moteur.adjust(slowWheelSpeed, speed);
    }
    else if (compareBits(code, "zzx00"))
    {
        moteur.adjust(speed, slowWheelSpeed);
    }
    else if (compareBits(code, "xx1xx") || (shouldGoStraight))
    {

        moteur.goForward(speed);
    }

    return compareBits(code, "00100");

}

bool Robot1::suivreLigne(char code) {
    return suivreLigne(code, getVitesse(), getVitesse() / 2);

}


uint8_t Robot1::receiveData() {
    timer.init();

    button.init();


    timer.setDurationSec(2);
    uint8_t compteur = 0;

    IRTransceiver ir;
    int message = 0;
    int channel = 0;
    int command = 0;

    while (true)
    {
        message = ir.receive();
        if(message != 0){
            channel = ir.getChannel(message);
            if(channel == 1){
                command = ir.getCommand(message);
                if(command >= 1 && command <= 4){
                    return command;
                }                
            }
        }

        if (button.getState())
        {

            button.setState(false);
            compteur++;
            if (compteur == 10)
            {
                compteur = 1;
            }
            timer.startTimer();
        }

        if (timer.isDone())
        {
            return compteur;
        }
    }

    return compteur;


}




/* Getters & Setters */



uint8_t Robot1::getVitesse() const {
    return vitesse;
}

void Robot1::setVitesse(uint8_t vitesse) {
    Robot1::vitesse = vitesse;
}


bool Robot1::isShouldGoStraight() const {
    return shouldGoStraight;
}

void Robot1::setShouldGoStraight(bool shouldGoStraight) {
    Robot1::shouldGoStraight = shouldGoStraight;
}

