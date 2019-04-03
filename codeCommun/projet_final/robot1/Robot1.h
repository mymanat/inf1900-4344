//
// Created by simon on 4/3/19.
//

#ifndef MAIN_ROBOT1_H
#define MAIN_ROBOT1_H

#include "../Robot.h"
#include "DEL.h"

class Robot1 : public Robot{
public:
    Robot1();


//    void run() override;
void run();

    void setSection(uint8_t section);

    uint8_t receiveData() ;

private:
    uint8_t section = 1;
    DEL del;
    Timer timer;
    Button button;
};


#endif //MAIN_ROBOT1_H
