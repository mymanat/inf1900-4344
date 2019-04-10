//
// Created by simon on 4/9/19.
//

#include "Section4.h"


bool Section4::evaluateState(uint8_t code) {
    switch (state) {

    }
    return true;
}

void Section4::evaluateAction(uint8_t code) {
    switch (state) {
        default:
            suivreLigne(code);
            break;
    }


}
