#define F_CPU 8000000
#include <avr/io.h> 
#include <util/delay.h>


int main()
{

  DDRA = 0xff; // PORT A est en mode sortie
  DDRD = 0x00;

  for(;;)
  {

    for(int i = 0; i < 3000; i++){
      int off = i / 30;
      int on = 100 - off;
      
      PORTA=0x01;

      for(int j = 0; j < on; j++){
        _delay_ms(0.01);
      }

      PORTA=0x00;

      for(int j = 0; j < off; j++){
        _delay_ms(0.01);
      }

    }


     
  }
  
  return 0; 
}
