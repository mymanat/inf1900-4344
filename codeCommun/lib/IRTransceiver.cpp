#include "IRTransceiver.h"

IRTransceiver::IRTransceiver() {}

const int TOLERANCE = 3;

void IRTransceiver::transmit(int command, int channel)
{
    char commandeBinaire[LONGUEUR_COMMANDE_IR];

    int message = command | (channel << 7);

    /*for(int i = LONGUEUR_COMMANDE_IR - 1; i >= 0; i--){
        commandeBinaire[i] = message & 1;
        message >>= 1;
    }*/

    /* Trouver la commande voulue en binaire */
    /*switch (commande)
    {
    case 0:
        strcpy(commandeBinaire, "000000000001");
        break;
    case 1:
        strcpy(commandeBinaire, "000000100001");
        break;
    case 2:
        strcpy(commandeBinaire, "000001000001");
        break;
    case 3:
        strcpy(commandeBinaire, "000001100001");
        break;
    case 4:
        strcpy(commandeBinaire, "000010000001");
        break;
    case 5:
        strcpy(commandeBinaire, "000010100001");
        break;
    }/*

    /* Initialiser la communication avec un signal haut de 2.4ms suivi d'un signal bas de 0.6ms */
    speaker_.playFrequency();
    _delay_ms(2.4);
    speaker_.arreterSon();
    _delay_ms(0.6);

    for (int i = 0; i < LONGUEUR_COMMANDE_IR; ++i)
    {
        if (message & 1)
        {
            speaker_.playFrequency();
            _delay_ms(1.2);
            speaker_.arreterSon();
            _delay_ms(0.6);
        }
        else
        {
            speaker_.playFrequency();
            _delay_ms(0.6);
            speaker_.arreterSon();
            _delay_ms(0.6);
        }

        message >>= 1;
    }
}

int IRTransceiver::receive()
{
    int burstLength = 0;
    int messageLength = 0;
    int message = 0;

    if (isSignalActive()){
        //PORTC = 0x05;
        while(!isWithinTolerance(burstLength, 24)){
            burstLength = measureBurstLength();
            //transmissionUART(burstLength);
            while(!isSignalActive()){
                //waits for next pulse
            }
            //PORTC = 0x00;
        }
        //PORTC = 0x05;
        do{
            burstLength = measureBurstLength();
            transmissionUART(burstLength);

            if(isWithinTolerance(burstLength, 6)){
                message |= (0 << messageLength);       //inutile, mais clarifie le code
            }
            else if(isWithinTolerance(burstLength, 12)){
                message |= (1 << messageLength);                
            }
            while(!isSignalActive()){
                //waits for next pulse
            }
            messageLength++;
        }while(!isWithinTolerance(burstLength, 24));
        //message >>= 1;

        /*if(cpt > 12)
            message = 0; */       
    }   

    return message;
}

/*bool IRTransceiver::estMaintenu(bool up, int duree){

    duree -= 1;
    for(int i = 0; i < duree; i++){
        if(isSignalActive() != up)
            return false;
        _delay_ms(0.1);
    }

    return true;
}*/

int IRTransceiver::measureBurstLength(){

    int length = 0;
    while(isSignalActive()){
        _delay_ms(0.1);
        length++;
    }

    return length;
}

bool IRTransceiver::isSignalActive(){
    //transmissionUART(PINA);
    //return converter_.lecture(7) < 500;
    return !(PINA & 128);
}

bool IRTransceiver::isWithinTolerance(int val, int target){

    if(val >= target - TOLERANCE && val <= target + TOLERANCE)
        return true;
    else
        return false;
        
}

int IRTransceiver::getCommand(int message){
    return message & 0b1111111;
}

int IRTransceiver::getChannel(int message){
    return message >> 7;
}