//
// Created by simon on 4/9/19.
//

#ifndef MAIN_SECTION1_H
#define MAIN_SECTION1_H

#include "Robot1.h"

/*  State 0 : SuivreLigne jusqu'a ce qu'il detecte la ligne
    State 1 : S'arreter, puis compter le nombre de fois que l'utilisateur appuie sur le bouton d'interruption
    State 2 : 
*/
class Section1 : public Robot1
{
  public:
    bool evaluateState(uint8_t code) override;

    void evaluateAction(uint8_t code) override;

  private:
    int message;
    int channel;
    int command;
    IRTransceiver ir;
};

#endif //MAIN_SECTION1_H
