#ifndef I_LASER_HPP
#define I_LASER_HPP

#include "./objectInterface.hpp"

class ILaser : public ObjectInterface
{
public:
  virtual void setPosition(const sf::Vector2f &vector) = 0;
  virtual void move() = 0;
  virtual void reset() = 0;
  virtual void playInvaderDeath() = 0;
};

#endif
