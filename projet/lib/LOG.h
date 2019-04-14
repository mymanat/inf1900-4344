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


#ifdef DEBUG
#define DEBUG_PRINT(x)   log_uart(x)
#define DEBUG_TRANSMIT(x) transmitUART(x)
#else
# define DEBUG_PRINT(x) do {} while (0) // code mort
#define DEBUG_TRANSMIT(x) do{} while(0)
#endif


#endif 
