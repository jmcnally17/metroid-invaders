#ifndef I_LASER_HPP
#define I_LASER_HPP

#include "./objectInterface.hpp"
#include "../wrappers/iRenderWindow.hpp"

class ILaser : public ObjectInterface
{
public:
  virtual void setPosition(const sf::Vector2f &vector) = 0;
  virtual void draw(IRenderWindow &window) const = 0;
  virtual void move() = 0;
};

#endif
