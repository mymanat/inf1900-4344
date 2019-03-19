#include <avr/io.h>

#include "LOG.h"
#include "memoire_24.h"
#include "moteurs.h"
#include "speaker.h"
#include "wait.h"

volatile bool debutExecution = false;
volatile uint8_t adresse = 0;
volatile uint8_t adresseBcl = 0;
volatile uint8_t comteurBcl = 0;

void debutBoucle(uint8_t cpt) {
  adresseBcl = adresse;
  compteurBcl = cpt;
}

void finBoucle() {
  if (comteurBcl != 0) {
    comteurBcl--;
    adresse = adresseBcl;
  }
}

void executerCommande(uint8_t commande, uint8_t data) {
  if (commande == 0x01)
    debutExecution = true;
  else if (commande == 0xFF)
    debutExecution = false;

  else if (debutExecution) {
    switch (commande) {
      case 0x02:
        attendre(data);
        break;
      case 0x44:
        allumerDEL(data);
        break;
      case 0x45:
        eteindreDEL(data);
        break;
      case 0x48:
        jouerSon(data);
        break;
      case 0x09:
        arreterSon();
        break;
      case 0x60:
      case 0x61:
        arreterMoteurs();
        break;
      case 0x62:
        avancer(data);
        break;
      case 0x63:
        reculer(data);
        break;
      case 0x64:
        tournerDroite();
        break;
      case 0x65:
        tournerGauche();
        break;
      case 0xC0:
        debutBoucle(data);
        break;
      case 0xC1:
        finBoucle();
        break;
    }
  }
}

int main() {
  initialisationUART();

  Memoire24CXXX memoire24CXXX;

  uint8_t commande = 0;
  uint8_t data = 0;

  uint16_t nbAdresses = 0;

  memoire24CXXX.lecture(0, &data);
  nbAdresses = data << 8;
  memoire24CXXX.lecture(1, &data);
  nbAdresses |= data;

  for (adresse = 2; adresse < nbAdresses; adresse += 2) {
    memoire24CXXX.lecture(adresse, &commande);
    memoire24CXXX.lecture(adresse + 1, &data);

    executerCommande(commande, data, adresse);
    /*transmissionUART(commande);
    transmissionUART(data);*/
  }

  /*while (true) {

      memoire24CXXX.lecture(adresse, &data);


      transmissionUART(data);

      adresse++;
  }*/
}
