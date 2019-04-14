//
// Created by simon on 4/3/19.
//

#include "TrackerSensor.h"

TrackerSensor::TrackerSensor() {
    init();
}

void TrackerSensor::updateDEL() {
    for (uint8_t i = 1; i < SENSOR_COUNT + 1; ++i)
    {
        del.setState(isBlack(i), i);
    }
}

void TrackerSensor::update() {
    for (uint8_t i = 0; i < SENSOR_COUNT; ++i)
    {
        uint16_t value = lecture(i);
        values[i] = value;

        if (shouldUpdateLED)
        {
            bool delState = valueIsBlack(value);
            del.setState(delState, i + 1);
        }
    }
}

bool TrackerSensor::valueIsBlack(uint16_t value) const {
    return value < blackValue + SENSOR_DELTA_BLACK;
}

uint8_t TrackerSensor::getSensorStateCode() const {
    uint8_t result = 0;

    for (char i = SENSOR_COUNT; i > 0; --i)
    {
        result |= (isBlack(i) << (i - 1));

    }
    return result;
}

bool TrackerSensor::isBlack(uint8_t sensorID) const {
    return valueIsBlack(getValue(sensorID));
}


uint16_t TrackerSensor::getValue(uint8_t sensorID) const {
    return values[sensorID - 1];

}

uint16_t TrackerSensor::getBlackValue() const {
    return blackValue;
}

void TrackerSensor::setBlackValue(uint16_t blackValue) {
    TrackerSensor::blackValue = blackValue;
}

void TrackerSensor::init() {

    can::init();
    DDR_TRACKER_SENSOR = MODE_INPUT;
    blackValue = getValue(SENSOR_MIDDLE_POS);
    setShouldUpdateLED(true);
}

bool TrackerSensor::isShouldUpdateLED() const {
    return shouldUpdateLED;
}

void TrackerSensor::setShouldUpdateLED(bool shouldUpdateLed) {
    shouldUpdateLED = shouldUpdateLed;
}



