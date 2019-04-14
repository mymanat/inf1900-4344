/*
 *
 * Fonctions qui permettent de communiquer avec le PC
 *
/ Created by Simon, Maxime, Simon and Samuel
/ Date : February 15, 2019
*/
#ifndef LOG_H
#define LOG_H

#include <avr/io.h>
#include "string.h"

/**
 * Pour transmettre un seul charactère
 * @param data La donnée
 */
void transmitUART(const uint8_t data);

char receptUART();


void initUART(void);


/**
 * Pour transmettre une chaîne constantes
 * @param words La chaîne (ex: "test")
 */
void log_uart(const char words[]);



#endif 
