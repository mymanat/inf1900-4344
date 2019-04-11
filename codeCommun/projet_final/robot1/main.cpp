#include <avr/io.h>

#include "Robot1.h"
#include "Section1.h"
#include "Section2.h"
#include "Section3.h"
#include "Section4.h"

void start(uint8_t section);

void start(Robot1 & robot1);

void start(uint8_t section) {
    if (section <= SECTION_COUNT && section > 0)
    {
        for (uint8_t i = 0; i < SECTION_COUNT; ++i)
        {
            switch (section)
            {
                case 1:
                {
                    Section1 section1;
                    section1.run();
                }
                    break;
                case 2:
                {
                    Section2 section2;
                    section2.run();
                }
                    break;
                case 3:
                {
                    Section3 section3;
                    section3.run();
                }
                    break;
                case 4:
                {
                    Section4 section4;
                    section4.run();
                }
                    break;
                default:
                    break;
            }


            ++section;
            section = (section == 4) ? 0 : section + 1;
        }
    }
}

void start(Robot1 & robot1) {
    uint8_t section = robot1.receiveData();

    DEL del;
    del.eteindre();
    del.allumer(section);
    wait(3000);

    start(section);

}

int main() {

    initialisationUART();
    Robot1 robot1;
    start(robot1);

}
