#include <avr/io.h>

#include "Utils.h"
#include "memoire_24.h"




int main()
{
    DDRB = MODE_ENTREE;
    DDRD = MODE_SORTIE;



    while(1){
        PORTD = PINB;
    }


}
