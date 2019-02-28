#define F_CPU 8000000
#include <avr/io.h> 
#include "can.h"


int main()
{

    DDRA = 0x00;
    DDRB = 0xff;

    int intensite = 0;
    bool ambreFlag = false;
    can cn;


    for(;;){

        intensite = cn.lecture(PINA);

        if(intensite > 0xb0){
            PORTB = 0x02;
        }

        else if(intensite < 0x30){
            PORTB = 0x01;
        }
        
        else{
            if(ambreFlag)
                PORTB = 0x01;
            else
                PORTB = 0x02;
            ambreFlag = !ambreFlag;            
        }
    }

    return 0; 
}
