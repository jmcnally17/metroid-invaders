#ifndef I_LASER_CANNON_HPP
#define I_LASER_CANNON_HPP

#include "./objectInterface.hpp"

class ILaserCannon : public ObjectInterface
{
public:
  ILaserCannon();
  ILaserCannon(float width, float height, float x, float y, ISprite *sprite);
  virtual void move(float x) = 0;
  virtual void fire() = 0;
  virtual void loseLife() = 0;
  virtual void resetPosition() = 0;
};

#endif
