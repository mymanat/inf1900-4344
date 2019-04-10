#include <avr/io.h>

#include "Robot1.h"
#include "Section3.h"
#include "Section2.h"


int main() {

//    initialisationUART();

    Section3 section3;
    section3.run();


//    Section2 section2;
//    section2.run();

    Speaker speaker;
    speaker.jouerSon(RE);
    DEL del;
    del.allumer();
    wait(500);
    speaker.arreterSon();
    del.eteindre();
    wait(500);
    del.allumer();

}
