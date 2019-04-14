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


/**
 * Permet de faire une rotation complète des bits
 * Ex: 0b11000 devient 0b00011
 * Le bit 5 prend la place du bit 1 et vis-versa
 * Le bit 4 prend la place du bit 2 et vis-versa
 * @param value Valeur originale
 * @param length Nombre de bits dans le nombre
 * @return La valeur avec les positions des bits inversées
 */
uint8_t invertBitsPos(uint8_t value, uint8_t length) ;

#endif