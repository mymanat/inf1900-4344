#define F_CPU 8000000
#include <avr/io.h> 
#include <util/delay.h>
#include <avr/interrupt.h>


volatile int s = 0;


//Liste des etats : ROUGE, AMBRE, VERT, ROUGE2, OFF, VERT2
ISR (INT0_vect) {
// laisser un delai avant de confirmer la réponse du
// bouton-poussoir: environ 30 ms (anti-rebond)
_delay_ms ( 30 );
// se souvenir ici si le bouton est pressé ou relâché

// changements d'états tels que ceux de la
// semaine précédente

s++;
s = s % 6;

// Voir la note plus bas pour comprendre cette instruction et son rôle

EIFR |= (1 << INTF0) ;

}

void initialisation ( void ) {

// cli est une routine qui bloque toutes les interruptions.
// Il serait bien mauvais d'être interrompu alors que
// le microcontroleur n'est pas prêt...
cli ();
// configurer et choisir les ports pour les entrées
// et les sorties. DDRx... Initialisez bien vos variables
DDRA = 0xff;
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
  
  enum State {ROUGE, AMBRE, VERT, ROUGE2, OFF, VERT2};
  bool ambreFlag = false;
  
  for(;;)
  {

    switch(s){
        case ROUGE : { 
            PORTA=0x01;
            break;
        }
        case AMBRE : { 
            if(ambreFlag)
                PORTA=0x01;
            else
                PORTA=0x02;
            ambreFlag = !ambreFlag;
            break;
        }
        case VERT : {
            PORTA=0x02;
            break;
        }
        case ROUGE2 : {
            PORTA=0x01;
            break;
        }
        case OFF : {
            PORTA=0x00;
            break;            
        }
        case VERT2 : {
            PORTA=0x02;
            break;
        }

        default   : break;
    }
    
  }
  
  return 0; 
}
