#ifndef IR_TRANSCIEVER
#define IR_TRANSCIEVER

#include <util/delay.h>
#include <string.h>

#include "Speaker.h"
#include "can.h"
#include "constantes.h"
#include "LOG.h"

class IRTransciever : public Speaker
{
public:
  IRTransciever();

  void transmettre(int commande, int canal);
  int recevoir();
  bool estMaintenu(bool up, int duree);
  int mesurerSignal();
  bool signalActif();
  bool respecteTolerance(int val, int target);
  int getCommand(int message);
  int getChannel(int message);

private:
  Speaker speaker_;
  can convertisseur_;
};

#endif //IR_TRANSCIEVER
