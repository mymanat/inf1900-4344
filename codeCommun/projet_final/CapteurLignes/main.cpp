#include <avr/io.h>

#ifdef DEBUG
#include <stdlib.h>
#endif

#include "Utils.h"
#include "memoire_24.h"
#include "constantes.h"
#include "wait.h"
#include "LOG.h"
#include "can.h"

#include "DEL.h"
#include "TrackerSensor.h"


int main() {
#ifdef DEBUG
    initialisationUART();
#endif


    TrackerSensor convertisseur;
    while (1)
    {
#ifdef DEBUG
        char str[16];
        uint16_t valeurLue = convertisseur.getValue(0);
        itoa(valeurLue, str, 10);
        log_uart("Sensor 0: ");
        log_uart(str);
        log_uart("\n");
#endif

        convertisseur.update();
    }
}
