#ifndef LASER_CANNON_HPP
#define LASER_CANNON_HPP

#include <SFML/Graphics.hpp>
#include "../wrappers/iSprite.hpp"
#include "../wrappers/iRenderWindow.hpp"

class LaserCannon
{
public:
  LaserCannon(ISprite &sprite);
  sf::Vector2f getPosition() const;
  void draw(IRenderWindow &window) const;

private:
  sf::Vector2f position_;
  ISprite &sprite_;
};

#endif
