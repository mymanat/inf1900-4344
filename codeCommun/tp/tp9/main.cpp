#include <avr/io.h>
#include "LOG.h"
#include "memoire_24.h"
#include "wait.h"

int main() {
    initialisationUART();


    Memoire24CXXX memoire24CXXX;

//    uint8_t donnes[] = "*P*O*L*Y*T*E*C*H*N*I*Q*U*E* *M*O*N*T*R*E*A*L*";

//    uint8_t longueur = sizeof(donnes);
//    memoire24CXXX.ecriture(adresse, donnes, longueur);

    wait(100);
    uint8_t word1 = 0;
    uint8_t *word = &word1;

    char phrase[1000];


    while (true) {
        char data = 0;
        data = receptionUART();
        char *ptr_data = &data;

        log_uart(ptr_data);
        log_uart("allo\n\n");

        memoire24CXXX.ecriture(adresse, donnes, longueur);

    }
    /*  while (true) {



          for (uint16_t adresse = 0; adresse < 1000 ; ++adresse) {
              memoire24CXXX.lecture(adresse, word);
              phrase[adresse] = *word;
          }
          log_uart(phrase);
          log_uart("\n\n[DEBUT]\n\n");
      }

      */

}
