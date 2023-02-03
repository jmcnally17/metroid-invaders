#ifndef LASER_HPP
#define LASER_HPP

#include <SFML/Graphics.hpp>
#include "../wrappers/iSprite.hpp"
#include "../wrappers/iRenderWindow.hpp"

class Laser
{
public:
  Laser(ISprite &sprite);
  sf::Vector2f getPosition() const;
  void setPosition(const sf::Vector2f &vector);
  void draw(IRenderWindow &window) const;

private:
  sf::Vector2f position_;
  ISprite &sprite_;
};

#endif
