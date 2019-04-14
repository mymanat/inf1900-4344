#include "IRTransceiver.h"

IRTransceiver::IRTransceiver() {}

const int TOLERANCE = 3;


void IRTransceiver::transmit(int command, int channel)
{
    int message = command | (channel << 7);
 
    /* Initialize transmission with a high signal for 2.4 ms and a low signal for 0.6 ms */
    speaker_.playFrequency();
    _delay_ms(2.4);
    speaker_.arreterSon();
    _delay_ms(0.6);

    for (int i = 0; i < LONGUEUR_COMMANDE_IR; ++i)
    {
        //high signal for 1.2 ms or 0.6 ms depending on current LSB
        if (message & 1)
        {
            speaker_.playFrequency();
            _delay_ms(1.2); 
        }
        else
        {
            speaker_.playFrequency();
            _delay_ms(0.6);
        }
        //low signal for 0.6 ms
        speaker_.arreterSon();
            _delay_ms(0.6);

        //once the LSB is sent, shift right to prepare for next bit
        message >>= 1;
    }
}

int IRTransceiver::receive()
{
    message = 0;
    int burstLength = 0;    //length (in 0.1 ms increments) of last high signal
    int messageLength = 0;  //current message length in bits

    if (isSignalActive()){
        //wait for next message start
        while(!isWithinTolerance(burstLength, 24)){
            burstLength = measureBurstLength();
            while(!isSignalActive()){
                //wait for next pulse
            }
        }
        do{
            burstLength = measureBurstLength();

            if(isWithinTolerance(burstLength, 6)){
                message_ |= (0 << messageLength);   //doesn't do anything, but clarifies code
            }
            else if(isWithinTolerance(burstLength, 12)){
                message_ |= (1 << messageLength);                
            }
            while(!isSignalActive()){
                //wait for next pulse
            }
            messageLength++;
        }while(!isWithinTolerance(burstLength, 24));      
    }  
    return message_;
}

int IRTransceiver::measureBurstLength(){

    int length = 0;
    while(isSignalActive()){
        _delay_ms(0.1);
        length++;
    }

    return length;
}

bool IRTransceiver::isSignalActive(){
    //returns true when PINA7 is on low state (signal active)
    return !(PINA & (1 << 7));
}

bool IRTransceiver::isWithinTolerance(int val, int target){
    //returns true if val is within target +/- TOLERANCE
    return val >= target - TOLERANCE && val <= target + TOLERANCE;    
}

int IRTransceiver::getCommand(){
    //command is located in the 7 LSB of the message
    return message_ & 0b1111111;
}

int IRTransceiver::getChannel(){
    //channel is located in the rest of the message
    return message_ >> 7;
}