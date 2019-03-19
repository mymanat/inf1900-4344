#include "moteurs.h"
#include "speaker.h"

int main() {
  initialisationSpeaker();
  jouerSon(45);
  _delay_ms(1000);
  jouerSon(46);
  _delay_ms(1000);
  jouerSon(47);
  _delay_ms(1000);
  jouerSon(48);
}
