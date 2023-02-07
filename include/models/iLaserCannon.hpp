#ifndef I_LASER_CANNON_HPP
#define I_LASER_CANNON_HPP

#include "./objectInterface.hpp"

class ILaserCannon : public ObjectInterface
{
public:
  virtual void move(float x) = 0;
  virtual void fire() = 0;
};

#endif
