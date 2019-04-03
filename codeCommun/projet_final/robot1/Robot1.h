//
// Created by simon on 4/3/19.
//

#ifndef MAIN_ROBOT1_H
#define MAIN_ROBOT1_H

#include <stdint-gcc.h>
#include "../Robot.h"

class Robot1 : Robot{
public:

    Robot1(uint8_t section);

    void run() override;

    void setSection(uint8_t section);

private:
    uint8_t section = 1;
};


#endif //MAIN_ROBOT1_H
