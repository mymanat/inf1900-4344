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

#define MOTOR_MAX_SPEED 170
#define MOTOR_SLOW_SPEED 130

#define MOTOR_ULTRA_SPEED 220 //VITESSE_MAX_ULTRA

class Motors : public Component
{
public:
  Motors();

  void init() override;

  void adjust(uint8_t left, uint8_t right);

  void goForward(int speed);

  void goBackward(int speed);

  void stop();

  void tournerDroite90();

  void tournerGauche90();

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

private:
  void adjustPWM(uint8_t a, uint8_t b);
};

#endif
