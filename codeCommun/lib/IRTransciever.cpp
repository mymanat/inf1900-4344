#include "IRTransciever.h"

IRTransciever::IRTransciever() {}

const int TOLERANCE = 3;

void IRTransciever::transmettre(int commande, int canal)
{
    char commandeBinaire[LONGUEUR_COMMANDE_IR];

    int message = canal | (commande << 5);


    for(int i = LONGUEUR_COMMANDE_IR - 1; i >= 0; i--){
        commandeBinaire[i] = message & 1;
        message >>= 1;
    }

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
        if (commandeBinaire[i] == '1')
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
    }
}

int IRTransciever::recevoir()
{
    int longSignal = 0;
    int cpt = 0;
    int message = 0;

    if (signalActif()){
        //PORTC = 0x05;
        while(!respecteTolerance(longSignal, 24)){
            longSignal = mesurerSignal();
            //transmissionUART(longSignal);
            while(!signalActif()){
                //waits for next pulse
            }
            //PORTC = 0x00;
        }
        //PORTC = 0x05;
        longSignal = mesurerSignal();
        while(!respecteTolerance(longSignal, 22)){
            longSignal = mesurerSignal();
            //transmissionUART(longSignal);

            if(respecteTolerance(longSignal, 6)){
                message |= 0;       //inutile, mais clarifie le code
            }
            else if(respecteTolerance(longSignal, 12)){
                message |= 1;                
            }
            while(!signalActif()){
                //waits for next pulse
            }
            message <<= 1;
            cpt++;
        }
        message >>= 1;

        /*if(cpt > 12)
            message = 0; */       
    }   

    return message >> 1;
}

bool IRTransciever::estMaintenu(bool up, int duree){

    duree -= 1;
    for(int i = 0; i < duree; i++){
        if(signalActif() != up)
            return false;
        _delay_ms(0.1);
    }

    return true;
}

int IRTransciever::mesurerSignal(){

    int cpt = 0;
    while(signalActif()){
        _delay_ms(0.1);
        cpt++;
    }

    return cpt * 2;
}

bool IRTransciever::signalActif(){
    return convertisseur_.lecture(7) < 500;
}

bool IRTransciever::respecteTolerance(int val, int target){
    bool retour = false;
    if(val >= target - TOLERANCE && val <= target + TOLERANCE)
        retour = true;
    return retour;
        
}

int IRTransciever::getCommand(int message){
    return message >> 5;
}

int IRTransciever::getChannel(int message){
    return message & 0b11111;
}