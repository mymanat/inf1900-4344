//
// Created by simon on 4/3/19.
//

#ifndef MAIN_TRACKERSENSOR_H
#define MAIN_TRACKERSENSOR_H


#include "Utils.h"


#include "can.h"
#include "LED.h"
#include "Component.h"

/**
 * Numero du capteur du milieu
 */
#define SENSOR_MIDDLE_POS 3

/**
 * Valeur permettant de différencier les valeurs noirs des blanches
 */
#define SENSOR_DELTA_BLACK 500

/**
 * Le nombre de capteurs disponibles
 */
#define SENSOR_COUNT 5

class TrackerSensor : public can{

public:
    TrackerSensor();

    void init() override;


/**
 * Permet de mettre à jour les valeurs en mémoire ainsi que l'état des DELs
 */
    void update();

    void updateDEL();


/**
 * Permet d'obtenir un code binaire représentant l'état des capteurs
 * Exemple: 0b11001
 * Les capteurs qui détectent du noir sont les capteurs 1, 4 et 5
 *
 * @return Le code
 */
    uint8_t getSensorStateCode() const;

/**
 * Retourne la valeur en fonction de l'ID du capteur
 * le capteur IR1 correspond à l'ID 1
 * @param sensorID L'ID
 * @return la valeur du capteur
 */
    uint16_t getValue(uint8_t sensorID) const;

/**
 * Permet  de déterminer si une valeur correspond au noir
 * @param value La valeur numérique
 * @return Si le capteur détecte du noir
 */
    bool valueIsBlack(uint16_t value) const;

    bool isBlack(uint8_t sensorID) const;

    bool isShouldUpdateDel() const;

    void setShouldUpdateDel(bool shouldUpdateDel);


    /* Getters & Setters */

    uint16_t getBlackValue() const;

    void setBlackValue(uint16_t blackValue);

private:
    uint16_t values[SENSOR_COUNT] = {0, 0, 0, 0, 0};
    uint16_t blackValue = 0;
    bool shouldUpdateDEL = true;
    LED del;

};


#endif //MAIN_TRACKERSENSOR_H
