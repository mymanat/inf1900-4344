/*
 * Nom: compteur 32 bits
 * Copyright (C) 2005 Matthew Khouzam
 * License http://www.gnu.org/copyleft/gpl.html GNU/GPL
 * Description: Ceci est un exemple simple de programme
 * Version: 1.1
 */

// +--------------+-------+--------------+----------+
// | Etat present | INPUT | Etat suivant | Sortie Z |
// +--------------+-------+--------------+----------+
// |      E0      |   0   |      E0      |     0    |
// +--------------+-------+--------------+----------+
// |      E0      |   1   |      E1      |     0    |
// +--------------+-------+--------------+----------+
// |      E1      |   0   |      E1      |     0    |
// +--------------+-------+--------------+----------+
// |      E1      |   1   |      E2      |     0    |
// +--------------+-------+--------------+----------+
// |      E2      |   0   |      E2      |     0    |
// +--------------+-------+--------------+----------+
// |      E2      |   1   |      E3      |     0    |
// +--------------+-------+--------------+----------+
// |      E3      |   0   |      E3      |     0    |
// +--------------+-------+--------------+----------+
// |      E3      |   1   |      E4      |     0    |
// +--------------+-------+--------------+----------+
// |      E4      |   0   |      E4      |     0    |
// +--------------+-------+--------------+----------+
// |      E4      |   1   |      E5      |     0    |
// +--------------+-------+--------------+----------+
// |      E5      |   X   |      E0      |     1    |
// +--------------+-------+--------------+----------+

/*
 *
 * Par 
 * Samuel Poulin 1960424
 * Simon Tran 1961278
 * Groupe 03
 *
 */

#include <avr/io.h>

#define F_CPU 8000000
#define PRESSED 0x04
#define DELAY 10
#define DELAY_1_SEC 1000
#include <util/delay.h>

enum Couleurs
{
    Eteint,
    Vert,
    Rouge
};
enum Etats
{
    E0,
    E1,
    E2,
    E3,
    E4,
    E5
};
int main()
{
    DDRB = 0xff; // PORT B est en mode sortie
    DDRD = 0x00; // PORT D est en mode entree

    int etat = E0;

    while (true)
    {

        switch (etat)
        {
        case E0:
        case E1:
        case E2:
        case E3:
        case E4:
            if (PIND & PRESSED)
            {
                ++etat;
                while (PIND & PRESSED)
                {
                    _delay_ms(DELAY);
                }
            }
            break;

        case E5:
            PORTB = Rouge;
            _delay_ms(DELAY_1_SEC);
            PORTB = Eteint;
            etat = E0;
            break;
        }
    }
    return 0;
}
