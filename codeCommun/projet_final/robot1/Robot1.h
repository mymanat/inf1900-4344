//
// Created by simon on 4/3/19.
//

#ifndef MAIN_ROBOT1_H
#define MAIN_ROBOT1_H

#include <stdint-gcc.h>
#include "../Robot.h"
#include "DEL.h"
#include "moteurs.h"
#include "TrackerSensor.h"

#include "Speaker.h"

class Robot1 : public Robot {
public:
    Robot1();

    void init() override;

    void run() override;

    void setSection(uint8_t section);

    uint8_t receiveData();

    bool suivreLigne();

    void section4(int & changement);

    void faireSection();

    void changerSection();

private:
    bool shouldStop = false;
    uint8_t section = 0;
    DEL del;
    Timer timer;
    moteurs moteur;
    TrackerSensor convertisseur;
    Button button;

    uint8_t vitesse_max = 175;
    uint8_t vitesse = vitesse_max;
    uint8_t lastDirection = 0;//1, 2d, 3g
};


#endif //MAIN_ROBOT1_H
