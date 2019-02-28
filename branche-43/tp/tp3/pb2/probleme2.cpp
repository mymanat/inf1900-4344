#define F_CPU 8000000
#include <avr/io.h> 
#include <util/delay.h>


//Liste des etats : ROUGE, AMBRE, VERT, ROUGE2, OFF, VERT2

int main()
{

    DDRA = 0xff;
    DDRD = 0x00;

    for(;;)
    {
        for(int i = 0; i < 600; i++){
            int on = (i / 120) * 25;
            int off = 100 - on;

            PORTA = 0x01;
            for(int j = 0; j < on; j++){
                _delay_ms(0.16666);
            }
            PORTA = 0x00;
            for(int j = 0; j < off; j++){
                _delay_ms(0.16666);
            }
        }

        for(int i = 0; i < 4000; i++){
            int on = (i / 800) * 25;
            int off = 100 - on;

            PORTA = 0x01;
            for(int j = 0; j < on; j++){
                _delay_ms(0.025);
            }
            PORTA = 0x00;
            for(int j = 0; j < off; j++){
                _delay_ms(0.025);
            }
        }
    }
  
    return 0; 
}
