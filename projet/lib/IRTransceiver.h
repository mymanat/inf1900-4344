#ifndef IR_TRANSCEIVER
#define IR_TRANSCEIVER

#include <util/delay.h>
#include <string.h>

#include "Speaker.h"
#include "can.h"
#include "Constantes.h"
#include "LOG.h"

class IRTransceiver : public Speaker
{
public:
  IRTransceiver();

  /**Transmits a message over ir protocol
   * @param command Command to be sent over ir protocol
   * @param channel Channel used for ir protocol
   */
  void transmit(int command, int channel);

  /**Receives a message transmitted over ir protocol
   * @return Message received over ir protocol
   */
  int receive();

  /**Measures the ir signal's length in high state
   * @return Signal burst length in 0.1 ms increments
   */
  int measureBurstLength();

  /**Checks if ir signal is active
   * @return Returns true if signal is high, false otherwise
   */
  bool isSignalActive();

  /**Checks if value is within tolerance
   * @param val Value to be compared
   * @param target Target value to be compared against
   * @return Returns true if val is within target +/- TOLERANCE
   */
  bool isWithinTolerance(int val, int target);

  int getCommand();
  int getChannel();

private:
  Speaker speaker_;
  can converter_;
  int message_;
};

#endif //IR_TRANSCEIVER