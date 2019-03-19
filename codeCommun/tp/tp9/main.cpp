#include <avr/io.h>

#include "Routine.h"
#include "memoire_24.h"
#include "Speaker.h"

Routine routine;

void lireEtExecuter()
{
    Memoire24CXXX memoire24CXXX;

    uint8_t commande = 0;
    uint8_t data = 0;

    uint16_t nbAdresses = 0;

    memoire24CXXX.lecture(0, &data);
    nbAdresses = data << 8;
    memoire24CXXX.lecture(1, &data);
    nbAdresses |= data;

    routine.getAdresse();

    for (routine.setAdresse(2); routine.getAdresse() < nbAdresses; routine.addToAdress(2))
    {

        memoire24CXXX.lecture(routine.getAdresse(), &commande);
        memoire24CXXX.lecture(routine.getAdresse() + 1, &data);

        routine.executerCommande(commande, data);
    }
}

int main()
{
    Speaker sp;
    sp.jouerSon(1);
    lireEtExecuter();
}
