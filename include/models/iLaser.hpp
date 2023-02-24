#ifndef I_LASER_HPP
#define I_LASER_HPP

#include "./objectInterface.hpp"

class ILaser : public ObjectInterface
{
public:
  ILaser();
  ILaser(float width, float height, float x, float y, ISprite *sprite);
  virtual void move() = 0;
  virtual void playMetroidDeath() const = 0;
};

#endif
