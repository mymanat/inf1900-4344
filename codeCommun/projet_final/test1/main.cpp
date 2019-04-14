#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

#include "Utils.h"
#include "memoire_24.h"
#include "constantes.h"
#include "wait.h"
#include "LOG.h"
#include "can.h"

void initialisation() 
{
    cli();

    DDRA = MODE_ENTREE;
    DDRB = MODE_ENTREE;
    DDRC = MODE_SORTIE;
    DDRD = MODE_SORTIE;
    
    sei();
}

int main()
{
    initialisation();
    PORTC = 0xff;
    int section = 4;
    //while (section == 0)
    //{
        //section = DONNÉE_INFRAROUGE;
    //}

    //int section = DONNÉE_INFRAROUGE;
    Moteur moteur;
    Del del;
    can convertisseur;

    wait(40 * TIMER_COUNT);

    switch (section)
​    {
        case 1:
            setBit(&PORTC, 0, POSITION_DEL_1);
            wait(120 * TIMER_COUNT);
            setBit(&PORTC, 1, POSITION_DEL_1);
            break;
        case 2:
            setBit(&PORTC, 0, POSITION_DEL_2);
            wait(120 * TIMER_COUNT);
            setBit(&PORTC, 1, POSITION_DEL_2);
            break;
        case 3:
            setBit(&PORTC, 0, POSITION_DEL_3);
            wait(120 * TIMER_COUNT);
            setBit(&PORTC, 1, POSITION_DEL_3);
            break;
        case 4:
            setBit(&PORTC, 0, POSITION_DEL_4);
            wait(120 * TIMER_COUNT);
            setBit(&PORTC, 1, POSITION_DEL_4);
            break;
    }
    int valeurNoir = convertisseur.lecture(3);
    moteur.avancer(126);
    wait(40 * TIMER_COUNT);
    moteur.arreterMoteurs();
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
void FaireSection()
{
    int section = 4;
    for(int i = 0; i < 4; ++i) 
    {
        switch (section)
​        {
            case 1:
                ChangerSection(section);
                break;
            case 2:
                ChangerSection(section);
                break;
            case 3:
                ChangerSection(section);
                break;
            case 4:
                ChangerSection(section);
                break;
        }
    }
}
