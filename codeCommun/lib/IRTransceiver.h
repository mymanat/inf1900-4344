#ifndef IR_TRANSCEIVER
#define IR_TRANSCEIVER

#include <util/delay.h>
#include <string.h>

#include "Speaker.h"
#include "can.h"
#include "constantes.h"
#include "LOG.h"

class IRTransceiver : public Speaker
{
public:
  IRTransceiver();

  void transmit(int command, int channel);
   int receive();
  //bool estMaintenu(bool up, int duree);
  int measureBurstLength();
  bool isSignalActive();
  bool isWithinTolerance(int val, int target);
  int getCommand(int message);
  int getChannel(int message);

private:
  Speaker speaker_;
  can converter_;
};

#endif //IR_TRANSCEIVER