//
// Created by simon on 4/3/19.
//

#ifndef MAIN_TRACKERSENSOR_H
#define MAIN_TRACKERSENSOR_H



#include "Utils.h"


#include "can.h"
#include "DEL.h"

#define SENSOR_POS 0
#define SENSOR_MIDDLE_POS 3
#define SENSOR_DELTA_BLACK 500

#define SENSOR_COUNT 5 //Le nombre de capteurs disponibles

class TrackerSensor : can {

public:
    TrackerSensor();



    void update();

    const uint16_t *getValues() const;

    uint16_t getValue(uint8_t index) const;

    uint16_t getBlackValue() const;

    void setBlackValue(uint16_t blackValue);


private:
    uint16_t values[SENSOR_COUNT] = {0, 0, 0, 0, 0};
    uint16_t blackValue;
    DEL del;

};


#endif //MAIN_TRACKERSENSOR_H
