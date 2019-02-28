#define F_CPU 8000000
#include <avr/io.h> 
#include <util/delay.h>


int main()
{

  DDRA = 0xff; // PORT A est en mode sortie
  DDRD = 0x00;
  enum State {INIT, ON};
  const double delais = 1000;
  bool push = false;
  int pushCount = 0;
  State currentState = INIT;
  for(;;)
  {

    switch(currentState){
      case INIT : { PORTA=0x00;
                    break;
                  }
      case ON   : { PORTA=0x01;
                    _delay_ms(delais);
                    currentState = INIT;
                    pushCount = 0;
                    break;
                  }
      default   : break;
    }


    if(PIND & 0x04)   //Is the logic here right?
    {
      _delay_ms(10);
      if(PIND & 0x04){
        push = true;
      }
    }
    else if(push){
      pushCount++;
      push = false;
    }

    /*if(push && currentState == INIT){
      pushCount++;
    }*/

    if(pushCount == 5){
      currentState = ON;
    }



    //PORTA=0x01;
    //while(true){
      
        
    //}
    //PORTA=0x02;
    /*while(true){
      if(PIND & 0x04)
        break;
    }    */      
  }
  
  return 0; 
}
