#ifndef LOG_H
#define LOG_H

#include <avr/io.h>
#include "string.h"

/**
 * Pour transmettre un seul charactère
 * @param donnee La donnée
 */
void transmissionUART(const uint8_t donnee);

char receptionUART();


void initialisationUART(void);


/**
 * Pour transmettre une chaîne constantes
 * @param mots La chaîne (ex: "test")
 */
void log_uart(const char mots[]);


#ifdef DEBUG
# define DEBUG_PRINT(x)   log_uart(x)
#else
# define DEBUG_PRINT(x) do {} while (0) // code mort
#endif


#endif 
