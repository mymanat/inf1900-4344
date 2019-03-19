#include "moteurs.h"

<<<<<<< HEAD
void initialisationMoteurs(void) {
  cli();
  DDRD = 0xff;
  sei();
}

void ajustementPWM(int pa, int pb) {
  OCR1A = 255 * ((float)pa / 100);
=======
void ajustementPWM(int a, int b) {
  // mise à un des sorties OC1A et OC1B sur comparaison

  // réussie en mode PWM 8 bits, phase correcte

  // et valeur de TOP fixe à 0xFF (mode #1 de la table 17-6

  // page 177 de la description technique du ATmega324PA)

  OCR1A = a;
>>>>>>> 38d1c7dd06c9fe5dc5cef99c62098322459e11f5

  OCR1B = b;

  // Mode 1 de Waveform Generation Mode, clear on compare match
  TCCR1A = (1 << WGM10) | (1 << COM1B1) | (1 << COM1A1);

  // Prescaler 8
  TCCR1B = (1 << CS11);
  TCCR1C = 0;
}
void avancer(int vitesse) {
    PORTD |= (0<<3);
    PORTD |= (0<<2); 
    ajustementPWM(vitesse, vitesse);    
}
void reculer(int vitesse) {
    PORTD |= (1<<3);
    PORTD |= (1<<2); 
    ajustementPWM(vitesse, vitesse);
}
void tournerDroite() {
    PORTD |= (0<<3);
    PORTD |= (1<<2);
    int rotationSpeed = 64;
    ajustementPWM(rotationSpeed, rotationSpeed);
    _delay_ms(2000);
    arreterMoteurs();  
}
void tournerGauche() {
    PORTD |= (1<<3);
    PORTD |= (0<<2);
    int rotationSpeed = 64;
    ajustementPWM(rotationSpeed, rotationSpeed);
    _delay_ms(2000);
    arreterMoteurs(); 
}
void arreterMoteurs(){
    PORTD |= (0<<3);
    PORTD |= (0<<2); 
    int zero = 0;
    ajustementPWM(zero, zero);
}

