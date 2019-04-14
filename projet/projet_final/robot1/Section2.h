//
// Created by simon on 4/9/19.
//

#ifndef MAIN_SECTION2_H
#define MAIN_SECTION2_H


#include "Robot1.h"

#include <math.h>

/**
 * Facteur de décélération lors des courbes
 */
#define SECTION2_DECEL_FACTOR 15

/**
 * Permet de décélérer la vitesse plus rapidement lorsque les capteurs aux extrémités détectent une ligne
 */
#define SECTION2_HARD_TURN_SPEED_FACTOR 5

/**
 * Vitesse Minimale
 */
#define SECTION2_MIN_SPEED 110

/**
 * Vitesse Maximale
 */
#define SECTION2_MAX_SPEED 200

/**
 * La borne supérieur de la variable hitCount
 */
#define SECTION2_HITCOUNT_MAX 8000

/**
 *
 * On utilise la formule suivante pour déterminer la vitesse du robot:
 * v=-0.00036*(x-500)^2+200
 * où x correspond au nombre de fois que le robot à dû tourner
 *
 * States:
 * 0: follow line until hard right turn
 * 1: hard right turn
 * 2:follow line
 */

class Section2 : public Robot1 {
public:

    Section2();

    bool evaluateState(uint8_t code) override;

    void evaluateAction(uint8_t code) override;

    /**
     * Permet d'évaluer la vitesse dans une courbe
     * @param code Le code des capteurs
     */
    void evaluateCurve(uint8_t code);

private:


    int16_t hitCountHalf = SECTION2_HITCOUNT_MAX / 2;

    /**
     * On incrémente cette valeur lorsque le robot tourne.
     * La vitese du robot suit une fonction quadratic dépendante de cette valeur
     */
    int16_t hitCount = hitCountHalf;

    /**
     * Variable utilisée par la formule mathématique qui calcule la vitesse
     */
    double a = 0;

};


#endif //MAIN_SECTION2_H
