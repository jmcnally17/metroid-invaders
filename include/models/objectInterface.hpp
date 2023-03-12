#ifndef OBJECT_INTERFACE_HPP
#define OBJECT_INTERFACE_HPP

#include <SFML/Graphics.hpp>
#include "../wrappers/iSprite.hpp"
#include "../wrappers/iRenderWindow.hpp"

class ObjectInterface
{
public:
  ObjectInterface();
  ObjectInterface(float x, float y, ISprite *sprite);
  virtual sf::Vector2f getPosition() const = 0;
  virtual void setPosition(const sf::Vector2f &position) = 0;
  virtual void draw(IRenderWindow &window) const = 0;
  virtual void reset() = 0;
  virtual sf::FloatRect getGlobalBounds() const = 0;
  virtual bool intersects(const sf::FloatRect &rectangle) const = 0;
  ;

protected:
  ISprite *sprite_;
};

#endif
