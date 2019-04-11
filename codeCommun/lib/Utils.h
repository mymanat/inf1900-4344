#ifndef UTILS_H
#define UTILS_H

#include "constantes.h"
#include "LOG.h"


/**
 * Permet de définir la valeur d'un bit à une position
 * @param variable Pointeur vers la variable
 * @param valeur nouvelle valeur du bit
 * @param bitIndex Position du bit
 */
void setBit(uint8_t *variable, bool valeur, uint8_t bitIndex);

void setBit(volatile uint8_t *variable, bool valeur, uint8_t bitIndex);

/**
 * Test si les bits du monde match la compareString
 * La valeur 'x' correspond à un "don't care" (ok pour 1 ou 0)
 * La fonction retourne vrai si la valeur contient au moins un '0' là où il y a le charactère 'y' dans la compareString
 * La fonction retourne vrai si la valeur contient au moins un '1' là où il y a le charactère 'y' dans la compareString
 *
 * La chaine doit etre de longueur 5
 * Exemple: value=0b10011
 * compareString="100xx"
 * Retourne vrai
 *
 * value=0b11111
 * compareString="101xy"
 * Retourne faux, car au moins un 'y' n'a pas de '0' correspondant
 *
 * value=0b10101
 * compareString="zzxxx"
 * retourne vrai, car au moins un 'z' a un '1'
 *
 */
bool compareBits(uint8_t value, const char compareString[]);


#endif