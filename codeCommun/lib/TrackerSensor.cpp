//
// Created by simon on 4/3/19.
//

#include "TrackerSensor.h"

TrackerSensor::TrackerSensor() {


    DDR_TRACKER_SENSOR = MODE_ENTREE;
    blackValue = getValue(SENSOR_MIDDLE_POS);

}


void TrackerSensor::update() {

    for (uint8_t i = SENSOR_POS; i < SENSOR_POS + SENSOR_COUNT; ++i)
    {
        uint16_t value = lecture(i);
        values[i - SENSOR_POS] = value;

        bool delState = value <= blackValue + SENSOR_DELTA_BLACK;
        del.setState(delState, i + 1);
    }
}

const uint16_t *TrackerSensor::getValues() const {
    return values;
}


uint16_t TrackerSensor::getValue(uint8_t index) const {
    return values[index];

}

uint16_t TrackerSensor::getBlackValue() const {
    return blackValue;
}

void TrackerSensor::setBlackValue(uint16_t blackValue) {
    TrackerSensor::blackValue = blackValue;
}





