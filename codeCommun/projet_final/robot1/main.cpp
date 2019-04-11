#include <avr/io.h>

#include "Robot1.h"
#include "Section3.h"
#include "Section2.h"
#include "Section4.h"


int main() {

//    Button button;
//    button.init();

//    while (!button.getState()) {

//    }
//
//    del.allumer();
    initialisationUART();
    Section3 section3;
    section3.run();
    Section4 section4;
    section4.run();
//    moteurs moteur;
//    moteur.arreterMoteurs();




//todo: sectio2 wtf




   //Section4 section4;
   //section4.run();


    //Speaker speaker;
    //speaker.jouerSon(RE);
    //del.allumer();
    //wait(500);
    //speaker.arreterSon();
    //del.eteindre();
    //wait(500);
    //del.allumer();
    //moteurs moteurs;
    //moteurs.arreterMoteurs();

}
