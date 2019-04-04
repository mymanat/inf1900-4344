#include <avr/io.h>
#include <stdio.h>

#include "Robot1.h"


int main() {

   Robot1 robot1;
   while(1) {
       wait(3000);
       robot1.run();
       robot1.init();

   }


}
