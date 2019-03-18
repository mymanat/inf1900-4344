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
    char adresse = 0;
    while(true){
        char data = receptionUART();

        memoire24CXXX.ecriture(adresse, data);


        adresse++;
    }


}