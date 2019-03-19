#ifndef LOG_H
#define LOG_H

#include <avr/io.h>
#include "string.h"

void transmissionUART(const char donnee);

char receptionUART();

void initialisationUART(void);

void log_uart(const char mots[]);

#endif 
