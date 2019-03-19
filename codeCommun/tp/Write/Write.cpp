//
// Created by simon on 3/18/19.
//


#include <avr/io.h>
#include "LOG.h"
#include "memoire_24.h"
#include "wait.h"
int main() {
    initialisationUART();

    Memoire24CXXX memoire24CXXX;
    uint8_t donnees[255];
    donnees[0]= receptionUART();
    donnees[1] = receptionUART();


    uint8_t size = (donnees[0] << 8) | donnees[1];



    for (uint8_t i = 2; i < size; ++i) {
        donnees[i] = receptionUART();
    }

    for (uint8_t i = 0; i < size; ++i) {
        memoire24CXXX.ecriture(i, donnees[i]);
//        transmissionUART(donnees[i]);
        wait(5);
    }




}