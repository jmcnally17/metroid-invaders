#ifndef LASER_HPP
#define LASER_HPP

#include <SFML/Graphics.hpp>
#include "../wrappers/iSprite.hpp"

class Laser
{
public:
  Laser(ISprite &sprite);
  sf::Vector2f getPosition() const;
  void setPosition(const sf::Vector2f &vector);

private:
  sf::Vector2f position_;
  ISprite &sprite_;
};

#endif
