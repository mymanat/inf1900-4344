#include "IRTransciever.h"

IRTransciever::IRTransciever() {}

void IRTransciever::transmettre(int commande)
{
    char commandeBinaire[LONGUEUR_COMMANDE_IR];

    /* Trouver la commande voulue en binaire */
    switch (commande)
    {
    case 0:
        strcpy(commandeBinaire, "000000000000");
        break;
    case 1:
        strcpy(commandeBinaire, "000000010000");
        break;
    }

    /* Initialiser la communication avec un signal haut de 2.4ms suivi d'un signal bas de 0.6ms */
    speaker_.playFrequency();
    _delay_ms(2.4);
    speaker_.arreterSon();
    _delay_ms(0.6);

    for (int i = 0; i < LONGUEUR_COMMANDE_IR; ++i)
    {
        if (commandeBinaire[i] == '1')
        {
            speaker_.playFrequency();
            _delay_ms(1.2);
            speaker_.arreterSon();
            _delay_ms(0.6);
        }
        else
        {
            speaker_.playFrequency();
            _delay_ms(0.6);
            speaker_.arreterSon();
            _delay_ms(0.6);
        }
    }
}

int IRTransciever::recevoir()
{
    if (convertisseur_.lecture(7) < 500)
    {
    }
}