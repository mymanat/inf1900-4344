#define F_CPU 8000000
#include <avr/io.h> 
#include <util/delay.h>
#include <avr/interrupt.h>


volatile bool enfonce = false;

ISR (INT0_vect) {
// laisser un delai avant de confirmer la réponse du
// bouton-poussoir: environ 30 ms (anti-rebond)
_delay_ms ( 30 );

enfonce = !enfonce;

EIFR |= (1 << INTF0) ;

}

void initialisation ( void ) {

// cli est une routine qui bloque toutes les interruptions.
// Il serait bien mauvais d'être interrompu alors que
// le microcontroleur n'est pas prêt...
cli ();
// configurer et choisir les ports pour les entrées
// et les sorties. DDRx... Initialisez bien vos variables
DDRB = 0xff;
DDRD = 0x00;
// cette procédure ajuste le registre EIMSK
// de l’ATmega324PA pour permettre les interruptions externes
EIMSK |= (1 << INT0) ;
// il faut sensibiliser les interruptions externes aux
// changements de niveau du bouton-poussoir
// en ajustant le registre EICRA
EICRA |= (1 << ISC00);
// sei permet de recevoir à nouveau des interruptions.
sei ();
}


int main()
{
    initialisation();
    
    for(;;)
    {
        int compteur = 0;
        PORTB = 0x00;
        enfonce = false;

        while(!enfonce){

        }

        while(enfonce && compteur <= 120){
            compteur++;
            _delay_ms(100);
        }

        for (int i = 0; i < 5; i++){
            PORTB = 0x02;
            _delay_ms(50);
            PORTB = 0x00;
            _delay_ms(50);
        }

        _delay_ms(2000);
        
        for(int i = 0; i < compteur / 2; i++){
            PORTB = 0x01;
            _delay_ms(250);
            PORTB = 0x00;
            _delay_ms(250);
        }

        PORTB = 0x02;
        _delay_ms(1000);
    }

    return 0; 
}
