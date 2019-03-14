#include <avr/io.h>
#include "LOG.h"
#include "memoire_24.h"

#include "wait.h"
int main(){
    initialisationUART();
    unsigned char mots[] = "[asdfa: Le robot en INF1900\n";


    log_uart(mots);


    Memoire24CXXX memoire24CXXX;

    uint8_t donnes[] = "*P*O*L*Y*T*E*C*H*N*I*Q*U*E* *M*O*N*T*R*E*A*L*";

    uint8_t longueur = sizeof(donnes);
    uint16_t adresse = 0x00;
    memoire24CXXX.ecriture(adresse, donnes, longueur);

    wait(100);
    uint8_t word1 = 0;
    uint8_t * word = &word1;


    memoire24CXXX.lecture(adresse, word);


    log_uart(word);
    log_uart(mots);

}
