#include <avr/io.h>

#include "Robot1.h"
#include "Section1.h"
#include "Section2.h"
#include "Section3.h"
#include "Section4.h"

int main()
{
    Section2 section2;
    section2.run();
    Section3 section3;
    section3.run();
    Section4 section4;
    section4.run();
}
