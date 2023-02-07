#ifndef OBJECT_INTERFACE_HPP
#define OBJECT_INTERFACE_HPP

#include <SFML/Graphics.hpp>
#include "../wrappers/iRenderWindow.hpp"

class ObjectInterface
{
public:
  virtual float getWidth() const = 0;
  virtual float getHeight() const = 0;
  virtual sf::Vector2f getPosition() const = 0;
  virtual void draw(IRenderWindow &window) const = 0;
};

#endif
