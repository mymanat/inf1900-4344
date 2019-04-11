//
// Created by simon on 4/9/19.
//

#include "Section3.h"

Section3::Section3() {
    setVitesse(VITESSE_LENT);
}


bool Section3::evaluateState(uint8_t code) {
    //transmissionUART(code);
    //transmissionUART(compareBits(0b11111, "11111"));
    switch (state)
    {
        case 0:
            if (compareBits(code, "11111"))
            {
                moteur.arreterMoteurs();
                button.init();

                convertisseur.setShouldUpdateDel(false);//todo

                state++;

            }
            break;
        case 1:
            if (button.getState())
            {
                moteur.init();
                /*if (state == 3)//todo
                {
                    return false;
                }
                else
                {
                    convertisseur.setShouldUpdateDel(true);//todo
                }*/
                state++;
            }
            break;
        case 2:
            if (compareBits(code, "11111"))
            {

                //convertisseur.setShouldUpdateDel(false);
                //del.eteindre();
                //del.allumer(2);//todo

                //moteur.arreterMoteurs();
                //button.init();
                state++;
            }
            break;
        case 3:
            if (compareBits(code, "00xx1"))
            {
                impair = false;
                state++;
            }
            else if (compareBits(code, "1xx00"))
            {
                impair = true;
                state += 2;
            }
            break;
        case 4:
            if (compareBits(code, "1xx00"))
            {
                transmissionUART(loopCounter);
                state += 2;
            }
            break;
        case 5:
            if (compareBits(code, "00xx1"))
            {
                transmissionUART(loopCounter);
                state++;
            }
            break;
        case 6:
            moteur.arreterMoteurs();
            if (!impair)
            {
                if(loopCounter < 100)
                {
                    del.allumer(2)
                }
                else
                {
                    del.allumer(1)
                }
            }
            else
            {
                if(loopCounter < 100)
                {
                    del.allumer(4)
                }
                else
                {
                    del.allumer(3)
                }
                
            }
            
            break;
    }
    return true;
}

void Section3::evaluateAction(uint8_t code) {
    //readData(code);

    switch (state)
    {
        case 0:
            suivreLigne(code);
            break;
        case 1:
        case 6:
            break;
        case 2:
            suivreLigne(code);
            break;
        case 3:
        case 4:
        case 5:
            suivreLigne(code);
            readData(code);
            break;

    }

}

void Section3::readData(uint8_t code) {
    /*if (compareBits(code, "1xxx1"))
    {
        transmissionUART(loopCounter);

    }*/
    loopCounter++;
}
