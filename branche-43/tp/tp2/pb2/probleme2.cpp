#define F_CPU 8000000
#include <avr/io.h> 
#include <util/delay.h>


//Liste des etats : ROUGE, AMBRE, VERT, ROUGE2, OFF, VERT2

int main()
{

  DDRA = 0xff;
  DDRD = 0x00;
  enum State {ROUGE, AMBRE, VERT, ROUGE2, OFF, VERT2};
  bool push = false;
  bool ambreFlag = false;
  State currentState = ROUGE;
  for(;;)
  {

    switch(currentState){
        case ROUGE : { 
            PORTA=0x01;
            if(push)
                currentState = AMBRE;
            break;
        }
        case AMBRE : { 
            if(ambreFlag)
                PORTA=0x01;
            else
                PORTA=0x02;
            ambreFlag = !ambreFlag;

            if(!push)
                currentState = VERT;
            break;
        }
        case VERT : {
            PORTA=0x02;
            if(push)
                currentState = ROUGE2;
            break;
        }
        case ROUGE2 : {
            PORTA=0x01;
            if(!push)
                currentState = OFF;
            break;
        }
        case OFF : {
            PORTA=0x00;
            if(push)
                currentState = VERT2;
            break;            
        }
        case VERT2 : {
            PORTA=0x02;
            if(!push)
                currentState = ROUGE;
            break;
        }

        default   : break;
    }


    if(PIND & 0x04)   //Is the logic here right?
    {
        if(!push){
            _delay_ms(10);
            if(PIND & 0x04){
                push = true;
            }
        }      
    }
    else
        push = false;




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
