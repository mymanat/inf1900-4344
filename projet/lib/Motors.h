#ifndef MOTEURS_H
#define MOTEURS_H

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include "Utils.h"
#include "Component.h"

#define MOTOR_RIGHT 1
#define MOTOR_LEFT 0

#define MOTOR_DIRECTION_FORWARD 1
#define MOTOR_DIRECTION_BACKWARD 0

/**
 * Durée de rotation pour faire 90 degrés
 */
#define MOTOR_ROTATION_DURATION_90_R 410
#define MOTOR_ROTATION_DURATION_90_L 425

/**
 * Coefficient pour modifier la vitesse du moteur qui tourne plus rapidement que l'autre
 */
#define MOTOR_IMBALANCE_COEFFICIENT 1.0

/**
 * Vitesse maximale et minimale utilisée.
 */
#define MOTOR_FAST_SPEED 170
#define MOTOR_SLOW_SPEED 130

#define MOTOR_ULTRA_SPEED 220 //VITESSE_MAX_ULTRA

#define MOTOR_MAXIMUM_SPEED 255

class Motors : public Component
{
public:
  /*
  / Constructeur par défaut de la classe objet Motors.
  */
  Motors();

  /*
  / Override de la méthode init().
  */
  void init() override;

  /*
  / Méthode pour ajuster la vitesse des roues séparement.
  */
  void adjust(uint8_t left, uint8_t right);

  /*
  / Méthode pour faire avancer le robot tout droit devant.
  */
  void goForward(int speed);

  /*
  / Méthode pour faire reculer le robot.
  */
  void goBackward(int speed);

  /*
  / Méthode pour faire arreter le robot.
  */
  void stop();

  /*
  / Méthode pour faire tourner le robot de 90 degrés vers la droite.
  */
  void turnRight90();

  /*
  / Méthode pour faire tourner le robot de 90 degrés vers la gauche.
  */
  void turnLeft90();

  /**
 * Permet de définir la direction d'un moteur spécifique
 * @param direction la direction
 * @param motorID Le numero du moteur
 */
  void setMotorDirection(bool direction, bool motorID);

  /**
     * Permet de définir la direction des 2 moteurs en même temps
     * @param direction 1 pour avancer, 0 pour reculer
     */
  void setDirection(bool direction);

  /*
  / Méthode qui permet d'ajuster la puissance des moteurs.
  */
private:
  void adjustPWM(uint8_t a, uint8_t b);
};

#endif
