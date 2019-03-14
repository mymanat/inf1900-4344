#ifndef LOG_H
#define LOG_H
#include <avr/io.h>
#include <util/delay.h>

void initialisationUART();
void transmissionUART(uint8_t donnee);
void log_uart(unsigned char mots[]);

#endif 
