#include <avr/io.h>
#include "log.h"

int main(){
    initialisationUART();
    char mots[] = "TEST: Le robot en INF1900\n";


    log_uart(mots);

}
