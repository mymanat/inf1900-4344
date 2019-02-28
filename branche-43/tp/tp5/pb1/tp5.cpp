#define F_CPU 8000000
#include <avr/io.h> 
#include <util/delay.h>

#include "memoire_24.cpp"
const int temps = 5;
int main()
{
  DDRA = 0xff; // PORT A est en mode sortie
  Memoire24CXXX memoire;
  uint8_t donnee[] = "*P*O*L*Y*T*E*C*H*N*I*Q*U*E* *M*O*N*T*R*E*A*L*";
  uint8_t longueur = sizeof(donnee);
  uint16_t adresse = 0x00;
  memoire.ecriture(adresse, donnee, longueur);
  _delay_ms (5 * longueur);
  
  uint8_t donneelu[longueur];
  memoire.lecture(adresse, donneelu);
  bool memeChaine = true;
  for(int i = 0; i < longueur; i++){
    if(donnee[i] != donneelu[i]){
      memeChaine = false;
    }
  }
  if(memeChaine){
    PORTA = 0x02;
  }
  else {
    PORTA = 0;
  }
  
  return 0; 
}

