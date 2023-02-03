#ifndef I_LASER_HPP
#define I_LASER_HPP

#include <SFML/Graphics.hpp>

class ILaser
{
public:
  virtual float getWidth() const = 0;
  virtual float getHeight() const = 0;
  virtual sf::Vector2f getPosition() const = 0;
  virtual void setPosition(const sf::Vector2f &vector) = 0;
};

#endif
