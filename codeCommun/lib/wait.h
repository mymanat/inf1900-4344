#ifndef WAIT_H
#define WAIT_H

#include <avr/io.h>

#include <util/delay.h>

/**
 * Fonction prise du code source de _delay_ms(double __ms) et adaptée pour accepter les paramètres variables
 * https://www.nongnu.org/avr-libc/user-manual/delay_8h_source.html
 *
 */
void wait(double __ms);

#endif