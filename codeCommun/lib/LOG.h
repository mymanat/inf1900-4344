#ifndef LOG_H
#define LOG_H

#include <avr/io.h>
#include "string.h"

void transmissionUART(const char donnee);

char receptionUART();

void initialisationUART(void);


void log_uart(const char mots[]);


#ifdef DEBUG
# define DEBUG_PRINT(x)   log_uart(x)
#else
# define DEBUG_PRINT(x) do {} while (0) // code mort
#endif


#endif 
