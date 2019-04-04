//
// Created by simon on 4/3/19.
//

#ifndef MAIN_ROBOT1_H
#define MAIN_ROBOT1_H

#include "../Robot.h"
#include "DEL.h"
#include "moteurs.h"
#include "TrackerSensor.h"

class Robot1 : public Robot {
public:
    Robot1();


    void run() override;

    void setSection(uint8_t section);

    uint8_t receiveData();

    void suivreLigne();

    void section4(int & changement);

    void faireSection();

    void changerSection();

private:
    uint8_t section = 0;
    DEL del;
    Timer timer;
    moteurs moteur;
    TrackerSensor convertisseur;
    Button button;
};


#endif //MAIN_ROBOT1_H
