//
// Created by simon on 4/9/19.
//

#include "Section1.h"

bool Section1::evaluateState(uint8_t code)
{
    if (state != 1)
    {
        state = 0;
    }
    return true;
}

void Section1::evaluateAction(uint8_t code)
{
    if (state == 0)
    {
        moteur.tournerGauche90();
        _delay_ms(1000);
        moteur.avancer(VITESSE_MAX);
        _delay_ms(2500);
        moteur.arreterMoteurs();
        _delay_ms(1000);
        moteur.tournerDroite90();
        state++;
    }
    if (state == 1)
    {
    }
}
