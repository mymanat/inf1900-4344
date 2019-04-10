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


//todo
#include "../../lib/DEL.h"
#include "../../lib/Timer.h"
#include "../../lib/moteurs.h"
#include "../../lib/TrackerSensor.h"
#include "../../lib/Button.h"
#include "../../lib/Speaker.h"


#define VITESSE_MAX 170
#define VITESSE_LENT 100
#define DELTA_V 20


class Robot1 : public Robot {
public:

    Robot1();

    void init() override;

    void run() override;


    virtual bool evaluateState(uint8_t code) ;

    virtual void evaluateAction(uint8_t code);


    bool suivreLigne(char code);
    bool suivreLigne(char code, uint8_t speed, uint8_t turnSpeed);

    uint8_t receiveData();


    // Getters & Setters

    void setSection(uint8_t section);

    uint8_t getSection() const;

    uint8_t getVitesse() const;

    void setVitesse(uint8_t vitesse);


protected:


    DEL del;
    Timer timer;
    moteurs moteur;
    TrackerSensor convertisseur;
    Button button;
    Speaker speaker;


    uint8_t state = 0;

private:

    uint8_t section = 0;


    uint8_t vitesse = VITESSE_MAX;


};


#endif //MAIN_ROBOT1_H
