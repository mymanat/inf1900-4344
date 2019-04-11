#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <avr/io.h>

#define DDR_TRACKER_SENSOR DDRA

#define DDR_PWM DDRD

#define DDR_MOTEUR DDRD

#define TIMER_COUNT 25

#define PORT_MOTEUR PORTD
#define PIN_MOTEUR_GAUCHE (uint8_t)6
#define PIN_MOTEUR_DROITE (uint8_t)7

#define DDR_DEL DDRC
#define PORT_DEL PORTC

#define DDR_BTN_INTERRUPT DDRD

#define PORT_SPEAKER PORTB
#define DDR_SPEAKER DDRB

#define MODE_SORTIE 0xff
#define MODE_ENTREE 0x00

#define POSITION_DEL_1 0
#define POSITION_DEL_2 1
#define POSITION_DEL_3 2
#define POSITION_DEL_4 3
#define POSITION_DEL_5 4


/** Nombre de sections au total */
#define SECTION_COUNT 4

#define LONGUEUR_COMMANDE_IR 12

enum Couleur {
    Rouge,
    Vert,
    Ambree,
    Eteint
};

/* ---- Timer ---- */ //todo move
#define CNT_NO_CLOCK_SOURCE (0 << CS02) | (0 << CS01) | (0 << CS00)
#define CNT_NO_PRESCALING (0 << CS02) | (0 << CS01) | (1 << CS00)
#define CNT_PRESCALER_8 (0 << CS02) | (1 << CS01) | (0 << CS00)
#define CNT_PRESCALER_64 (0 << CS02) | (1 << CS01) | (1 << CS00)
#define CNT_PRESCALER_256 (1 << CS02) | (0 << CS01) | (0 << CS00)
#define CNT_PRESCALER_1024 (1 << CS02) | (0 << CS01) | (1 << CS00)

#endif
