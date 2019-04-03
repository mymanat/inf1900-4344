#include <avr/io.h>
#include <stdio.h>

#include "Robot1.h"


int main() {
    Robot1 robot1;
    wait(3000);//Wait 3 seconds
    robot1.run();


}
