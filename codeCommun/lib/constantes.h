#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <avr/io.h>
//#include <avr/iom324pa.h> //TODO: Remove

#define DDR_PWM DDRD


#define DDR_DEL DDRA
#define PORT_DEL PORTA


#define MODE_SORTIE 0xff;
#define MODE_ENTREE 0x00

enum Couleur {Rouge, Vert, Ambree, Eteint};

#endif
