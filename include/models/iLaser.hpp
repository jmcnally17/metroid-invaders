#ifndef I_LASER_HPP
#define I_LASER_HPP

#include "./objectInterface.hpp"

class ILaser : public ObjectInterface
{
public:
  ILaser();
  ILaser(float width, float height, float x, float y, ISprite *sprite);
  virtual void setPosition(const sf::Vector2f &vector) = 0;
  virtual void move() = 0;
  virtual void reset() = 0;
  virtual void playInvaderDeath() = 0;
};

#endif
