#ifndef CONSTANTES_H
#define CONSTANTES_H


#define DDR_TRACKER_SENSOR DDRA


#define DDR_MOTOR DDRD

#define BATTERY_MULTIPLIER 1


#define PORT_MOTOR PORTD
#define PIN_LEFT_MOTOR (uint8_t)6
#define PIN_RIGHT_MOTOR (uint8_t)7

#define DDR_LED DDRC
#define PORT_LED PORTC

#define DDR_INT_BTN DDRD

#define DDR_SPEAKER DDRB

#define MODE_OUTPUT 0xff
#define MODE_INPUT 0x00

/**
 * Le nombre de DELs
 */
#define LED_COUNT 5
#define POSITION_LED_1 0
#define POSITION_LED_2 1
#define POSITION_LED_3 2
#define POSITION_LED_4 3
#define POSITION_LED_5 4
#define POSITION_ONBOARD_LED 6


/** Nombre de sections au total */
#define SECTION_COUNT 4

#define LONGUEUR_COMMANDE_IR 12



/*
 * Délais pour s'assurer de la précision des mouvements
 */
#define TRANSITION_DELAY_1 100
#define TRANSITION_DELAY_2 200

#define DELAY_1_SEC 1000

#endif
