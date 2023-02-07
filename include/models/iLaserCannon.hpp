#ifndef I_LASER_CANNON_HPP
#define I_LASER_CANNON_HPP

#include "./objectInterface.hpp"
#include "../wrappers/iRenderWindow.hpp"

class ILaserCannon : public ObjectInterface
{
public:
  virtual void draw(IRenderWindow &window) const = 0;
  virtual void move(float x) = 0;
  virtual void fire() = 0;
};

#endif
