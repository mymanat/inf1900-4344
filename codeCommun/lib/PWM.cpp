//
// Created by simon on 3/18/19.
//

#include "PWM.h"



void PWM::ajustementPWM(float pa, float pb) const{
    // mise à un des sorties OC1A et OC1B sur comparaison

    // réussie en mode PWM 8 bits, phase correcte

    // et valeur de TOP fixe à 0xFF (mode #1 de la table 17-6

    // page 177 de la description technique du ATmega324PA)

    OCR1A = pa;//255 * ((float)pa / 100);

    OCR1B = pb;//255 * ((float)pb / 100);

    // division d'horloge par 8 - implique une frequence de PWM fixe

    TCCR1A = (1 << WGM10) | (1 << COM1B1) | (1 << COM1A1);

    TCCR1B = (1 << CS11);

    TCCR1C = 0;
}




PWM::PWM() {
    // cli est une routine qui bloque toutes les interruptions.
    // Il serait bien mauvais d'être interrompu alors que
    // le microcontroleur n'est pas prêt...

    cli();

    // configurer et choisir les ports pour les entrées
    // et les sorties. DDRx... Initialisez bien vos variables

    DDR_PWM = MODE_SORTIE;

    // cette procédure ajuste le registre EIMSK
    // de l’ATmega324PA pour permettre les interruptions externes

    EIMSK |= (1 << INT0);

    // il faut sensibiliser les interruptions externes aux
    // changements de niveau du bouton-poussoir
    // en ajustant le registre EICRA

    EICRA |= (1 << ISC00);

    // sei permet de recevoir à nouveau des interruptions.

    sei();


}
