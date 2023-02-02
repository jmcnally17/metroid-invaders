#ifndef I_LASER_CANNON_HPP
#define I_LASER_CANNON_HPP

#include "../wrappers/iRenderWindow.hpp"

class ILaserCannon
{
public:
  virtual sf::Vector2f getPosition() const = 0;
  virtual void draw(IRenderWindow &window) const = 0;
};

#endif
