//
// Created by simon on 4/3/19.
//

#ifndef MAIN_ROBOT_H
#define MAIN_ROBOT_H

#include "Utils.h"

#include "Timer.h"
#include "Button.h"
#include "wait.h"
#include "Component.h"


class Robot : public Component {

public:
    virtual void run() = 0;


private:
};


#endif //MAIN_ROBOT_H
