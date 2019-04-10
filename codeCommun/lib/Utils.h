#ifndef UTILS_H
#define UTILS_H

#include "constantes.h"
#include "LOG.h"


void setBit(uint8_t *variable, bool valeur, uint8_t bitIndex);
void setBit(volatile uint8_t *variable, bool valeur, uint8_t bitIndex) ;

bool compareBits(uint8_t value, char compareString[]);




#endif