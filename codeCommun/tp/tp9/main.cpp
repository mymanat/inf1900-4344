#include <avr/io.h>

#include "LOG.h"
#include "memoire_24.h"
#include "wait.h"

int main() {
    initialisationUART();

    Memoire24CXXX memoire24CXXX;

    uint8_t data = 0;
    char adresse = 0;
    while (true) {

        memoire24CXXX.lecture(adresse, &data);
        transmissionUART(data);

        adresse++;
    }


}
