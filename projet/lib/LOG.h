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
