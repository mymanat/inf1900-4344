//
// Created by simon on 4/3/19.
//

#include "TrackerSensor.h"

TrackerSensor::TrackerSensor() {


    DDR_TRACKER_SENSOR = MODE_ENTREE;
    blackValue = getValue(SENSOR_MIDDLE_POS);

}

/**
 * Permet de mettre à jour les valeurs en mémoire ainsi que l'état des DELs
 */
void TrackerSensor::update() {
    for (uint8_t i = SENSOR_POS; i < SENSOR_POS + SENSOR_COUNT; ++i)
    {
        uint16_t value = lecture(i);
        values[i - SENSOR_POS] = value;

        bool delState = value <= blackValue + SENSOR_DELTA_BLACK;
        del.setState(delState, i + 1);
    }
}

/**
 * Retourne le tableau contenant les valeurs.
 * Le capteur IR1 correspond à l'index 0
 */
const uint16_t *TrackerSensor::getValues() const {
    return values;
}

/**
 * Retourne la valeur en fonction de l'ID du capteur
 * le capteur IR1 correspond à l'ID 1
 * @param sensorID L'ID
 * @return la valeur du capteur
 */
uint16_t TrackerSensor::getValue(uint8_t sensorID) const {
    return values[sensorID-1];

}

uint16_t TrackerSensor::getBlackValue() const {
    return blackValue;
}

void TrackerSensor::setBlackValue(uint16_t blackValue) {
    TrackerSensor::blackValue = blackValue;
}





