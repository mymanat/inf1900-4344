//
// Created by simon on 4/3/19.
//

#include "Robot1.h"


Robot1::Robot1() {
    setSection(receiveData());

    del.eteindre();

    del.allumer(section);

}

void Robot1::run() {

}

void Robot1::setSection(uint8_t section) {
    Robot1::section = section;
}


uint8_t Robot1::receiveData() {
    uint8_t compteur = 0;

    timer.setDurationSec(2);


    uint8_t data = 0;
    while (!data)
    {


        if (button.getState())
        {
            button.setState(false);
            compteur++;
            if (compteur == 10)
            {
                compteur = 0;
            }
            timer.startTimer();
        }

        if (timer.isDone())
        {
            data = compteur;
        }

        //todo: data receive from IR
    }

    return compteur;
}
