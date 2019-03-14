#include <avr/io.h>
#include "LOG.h"


int main(){
    initialisationUART();
    char mots[] = "test1: Le robot en INF1900\n";


    log_uart(mots);

}
