#ifndef OBJECT_INTERFACE_HPP
#define OBJECT_INTERFACE_HPP

#include <SFML/Graphics.hpp>

class ObjectInterface
{
public:
  virtual float getWidth() const = 0;
  virtual float getHeight() const = 0;
  virtual sf::Vector2f getPosition() const = 0;
};

#endif
