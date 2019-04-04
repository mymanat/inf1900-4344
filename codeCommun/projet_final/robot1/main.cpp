#include <avr/io.h>
#include <stdio.h>

#include "Robot1.h"
#include "../../lib/Button.h"


int main() {
    DEL del;
    Button button;

    DDRD = MODE_ENTREE;
    DDRC = MODE_SORTIE;
    EICRA |= (1 << ISC00);

//    while(1) {
//
//        if (button.getState())
//        {
//
//            PORTC = 0b10101010;
//        }
//    }
//    Robot1 robot1;
//    wait(3000);//Wait 3 seconds
//    robot1.run();

//DEL del;
//    del.allumer();

}
