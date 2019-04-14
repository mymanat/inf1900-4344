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
  int measureBurstLength();
  bool isSignalActive();
  bool isWithinTolerance(int val, int target);
  int getCommand();
  int getChannel();

private:
  Speaker speaker_;
  can converter_;
  int message_;
};

#endif //IR_TRANSCEIVER