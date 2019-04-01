#include <avr/io.h>

#include "Utils.h"
#include "memoire_24.h"




int main()
{
    DDRB = MODE_ENTREE;
    DDRD = MODE_SORTIE;
    int section = DONNÉE_INFRAROUGE;
    Moteur moteur;
    Del del;


    //while(1){
        //PORTD = PINB;
    //}
    
    while(section != 1 || section != 2 || section != 3 || section != 4)
    {
    }
    switch (section)
​    {
        case 1:
            del.allumer(1);
            wait(120 * TIMER_COUNT)
            del.eteindre(1);
            break;
        case 2:
            del.allumer(2);
            wait(120 * TIMER_COUNT)
            del.eteindre(2);
            break;
        case 3:
            del.allumer(4);
            wait(120 * TIMER_COUNT)
            del.eteindre(4);
            break;
        case 4:
            del.allumer(8);
            wait(120 * TIMER_COUNT)
            del.eteindre(8);
            break;
    }  
    for(int i = 0; i < 4; ++i) 
    {
        switch (section)
​        {
            case 1:
                damn;
                ChangerSection(section);
                break;
            case 2:
                damn;
                ChangerSection(section);
                break;
            case 3:
                damn;
                ChangerSection(section);
                break;
            case 4:
                damn
                ChangerSection(section);
                break;
        }
    }
    return 0;
}
void ChangerSection(int& sectionActuelle)
{
    if (sectionActuelle == 4)
    {
        sectionActuelle = 1;
    }
    else
    {
        ++sectionActuel;
    }
}
