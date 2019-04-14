/*
 * Simon Tran
 *
 * Fichier qui contient plusieurs constantes qui concernent la façon dont
 * les différents périphériques sont branchés au robot
 */



#ifndef CONSTANTES_H
#define CONSTANTES_H

/**
 *
 * Constante multipliée aux vitesses données aux moteurs afin de compenser
 * le faible niveau des batteries
 *
 * Mettre à 1 pour des batteries pleines
 */
#define BATTERY_MULTIPLIER 1


/* Redéfinition des modes d'entré et de sortie */

#define MODE_OUTPUT 0xff
#define MODE_INPUT 0x00


/* Redéfinitions des Data Direction Registers */

#define DDR_TRACKER_SENSOR DDRA
#define DDR_SPEAKER DDRB
#define DDR_LED DDRC
#define DDR_INT_BTN DDRD
#define DDR_MOTOR DDRD


/* Redéfinitions des ports */

#define PORT_LED PORTC
#define PORT_MOTOR PORTD


/* Redéfinitions des pins */

#define PIN_LEFT_MOTOR (uint8_t)6
#define PIN_RIGHT_MOTOR (uint8_t)7



/**
 * Permet de vérifier si le bouton INT0 est appuyé
 */
#define BTN_PRESSED PIND & 0x04



/**
 * Le nombre de DELs
 */
#define LED_COUNT 5


/* La position des DELs. Le fil négatif doit être branché sur le numéro associé */

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

#define TRANSITION_DELAY_LONG 750
#define TRANSITION_DELAY_VERY_LONG 1500

#define DELAY_1_SEC 1000

#endif
