#include "Motors.h"

void Motors::adjustPWM(uint8_t a, uint8_t b) {
    // mise à un des sorties OC1A et OC1B sur comparaison
    // réussie en mode PWM 8 bits, phase correcte
    // et valeur de TOP fixe à 0xFF (mode #1 de la table 17-6
    // page 177 de la description technique du ATmega324PA)
    OCR1A = a;
    OCR1B = b * COEFFICIENT_MOTEUR_TROP_VITE;
    // division d'horloge par 8 - implique une frequence de PWM fixe
    TCCR1A = (1 << WGM10) | (1 << COM1B1) | (1 << COM1A1);
    TCCR1B = (1 << CS11);
    TCCR1C = 0;
}

void Motors::adjust(uint8_t gauche, uint8_t droite) {
    stop();
    adjustPWM(droite, gauche);
}

void Motors::setDirection(bool direction) {
    setMotorDirection(direction, MOTOR_LEFT);
    setMotorDirection(direction, MOTOR_RIGHT);
}

void Motors::setMotorDirection(bool direction, bool moteurNb) {
    setBit(&PORT_MOTEUR, !direction, (moteurNb) ? PIN_MOTEUR_GAUCHE : PIN_MOTEUR_DROITE);
}

void Motors::goForward(int vitesse) {
    stop();
    setDirection(MOTOR_DIRECTION_FORWARD);
    adjustPWM(vitesse, vitesse);
}

void Motors::goBackward(int vitesse) {
    stop();
    setDirection(MOTOR_DIRECTION_BACKWARD);
    adjustPWM(vitesse, vitesse);
}


void Motors::tournerGauche90() {
    setMotorDirection(MOTOR_DIRECTION_FORWARD, MOTOR_LEFT);
    setMotorDirection(MOTOR_DIRECTION_BACKWARD, MOTOR_RIGHT);
    adjust(MOTOR_MAX_SPEED, MOTOR_MAX_SPEED);
    _delay_ms(150);
    adjust(MOTOR_SLOW_SPEED, MOTOR_SLOW_SPEED);
    _delay_ms(MOTOR_ROTATION_DURATION_90);
    stop();
}

void Motors::tournerDroite90() {
    setMotorDirection(MOTOR_DIRECTION_BACKWARD, MOTOR_LEFT);
    setMotorDirection(MOTOR_DIRECTION_FORWARD, MOTOR_RIGHT);
    adjust(MOTOR_MAX_SPEED, MOTOR_MAX_SPEED);
    _delay_ms(150);
    adjust(MOTOR_SLOW_SPEED, MOTOR_SLOW_SPEED);
    _delay_ms(MOTOR_ROTATION_DURATION_90);
    stop();
}

void Motors::stop() {
    adjustPWM(0, 0);
}

Motors::Motors() {
    init();
}

void Motors::init() {
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
