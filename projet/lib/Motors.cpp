#include "Motors.h"

void Motors::adjustPWM(uint8_t a, uint8_t b)
{
    // mise à un des sorties OC1A et OC1B sur comparaison
    // réussie en mode PWM 8 bits, phase correcte
    // et valeur de TOP fixe à 0xFF (mode #1 de la table 17-6
    // page 177 de la description technique du ATmega324PA)
    OCR1A = a;
    OCR1B = b * MOTOR_IMBALANCE_COEFFICIENT;
    // division d'horloge par 8 - implique une frequence de PWM fixe
    TCCR1A = (1 << WGM10) | (1 << COM1B1) | (1 << COM1A1);
    TCCR1B = (1 << CS11);
    TCCR1C = 0;
}

void Motors::adjust(uint8_t left, uint8_t right)
{
    stop();
    adjustPWM(right * BATTERY_MULTIPLIER, left * BATTERY_MULTIPLIER);
}

void Motors::setDirection(bool direction)
{
    setMotorDirection(direction, MOTOR_LEFT);
    setMotorDirection(direction, MOTOR_RIGHT);
}

void Motors::setMotorDirection(bool direction, bool motorID)
{
    setBit(&PORT_MOTOR, !direction, (motorID) ? PIN_LEFT_MOTOR : PIN_RIGHT_MOTOR);
}

void Motors::goForward(int speed)
{
    stop();
    setDirection(MOTOR_DIRECTION_FORWARD);
    adjustPWM(speed, speed);
}

void Motors::goBackward(int speed)
{
    stop();
    setDirection(MOTOR_DIRECTION_BACKWARD);
    adjustPWM(speed, speed);
}

void Motors::tournerGauche90()
{
    setMotorDirection(MOTOR_DIRECTION_FORWARD, MOTOR_LEFT);
    setMotorDirection(MOTOR_DIRECTION_BACKWARD, MOTOR_RIGHT);
    adjust(255, 255);
    _delay_ms(MOTOR_ROTATION_DURATION_90_L);
    stop();
}

void Motors::tournerDroite90()
{
    setMotorDirection(MOTOR_DIRECTION_BACKWARD, MOTOR_LEFT);
    setMotorDirection(MOTOR_DIRECTION_FORWARD, MOTOR_RIGHT);
    adjust(255, 255);
    _delay_ms(MOTOR_ROTATION_DURATION_90_R);
    stop();
}

void Motors::stop()
{
    adjustPWM(0, 0);
}

Motors::Motors()
{
    init();
}

void Motors::init()
{
    // cli est une routine qui bloque toutes les interruptions.
    // Il serait bien mauvais d'être interrompu alors que
    // le microcontroleur n'est pas prêt...

    cli();

    // configurer et choisir les ports pour les entrées
    // et les sorties. DDRx... Initialisez bien vos variables

    DDR_MOTOR = MODE_OUTPUT;

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
