#include "moteurs.h"

void moteurs::ajustementPWM(uint8_t a, uint8_t b) {

    // mise à un des sorties OC1A et OC1B sur comparaison

    // réussie en mode PWM 8 bits, phase correcte

    // et valeur de TOP fixe à 0xFF (mode #1 de la table 17-6

    // page 177 de la description technique du ATmega324PA)

    OCR1A = a;

    OCR1B = b;

    // division d'horloge par 8 - implique une frequence de PWM fixe

    TCCR1A = (1 << WGM10) | (1 << COM1B1) | (1 << COM1A1);

    TCCR1B = (1 << CS11);

    TCCR1C = 0;
}

void moteurs::ajustementMoteur(uint8_t gauche, uint8_t droite) {
    arreterMoteurs();
    ajustementPWM(droite, gauche);
}

/**
 * Permet de définir la direction des 2 moteurs en même temps
 * @param direction 1 pour avancer, 0 pour reculer
 */
void moteurs::setDirection(bool direction) {
    setDirectionMoteur(direction, MOTEUR_GAUCHE);
    setDirectionMoteur(direction, MOTEUR_DROITE);
}

/**
 * Permet de définir la direction d'un moteur spécifique
 * @param direction la direction
 * @param moteurNb Le numero du moteur
 */
void moteurs::setDirectionMoteur(bool direction, bool moteurNb) {
    setBit(&PORT_MOTEUR, !direction, (moteurNb) ? PIN_MOTEUR_GAUCHE : PIN_MOTEUR_DROITE);
}

void moteurs::avancer(int vitesse) {
    arreterMoteurs();
    setDirection(DIRECTION_AVANCER);
    ajustementPWM(vitesse, vitesse);
}

void moteurs::reculer(int vitesse) {
    arreterMoteurs();
    setDirection(DIRECTION_RECULER);
    ajustementPWM(vitesse, vitesse);
}

void moteurs::tournerDroite() {
    arreterMoteurs();
    setDirectionMoteur(DIRECTION_AVANCER, MOTEUR_DROITE);
    int rotationSpeed = VITESSE_ROTATION;
    ajustementPWM(rotationSpeed, rotationSpeed);
    _delay_ms(DUREE_ROTATION);
    arreterMoteurs();
}

void moteurs::tournerGauche() {
    arreterMoteurs();
    setDirectionMoteur(DIRECTION_AVANCER, MOTEUR_GAUCHE);
    int rotationSpeed = VITESSE_ROTATION;
    ajustementPWM(rotationSpeed, rotationSpeed);
    _delay_ms(DUREE_ROTATION);
    arreterMoteurs();
}

void moteurs::arreterMoteurs() {
    setDirection(1);
    ajustementPWM(0, 0);
}

moteurs::moteurs() {
    init();
}

void moteurs::init() {
    // cli est une routine qui bloque toutes les interruptions.
    // Il serait bien mauvais d'être interrompu alors que
    // le microcontroleur n'est pas prêt...

    cli();

    // configurer et choisir les ports pour les entrées
    // et les sorties. DDRx... Initialisez bien vos variables

    DDR_MOTEUR = MODE_SORTIE;

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
