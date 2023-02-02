#ifndef LASER_CANNON_HPP
#define LASER_CANNON_HPP

#include <SFML/Graphics.hpp>
#include "../wrappers/iRenderWindow.hpp"

class LaserCannon
{
public:
  LaserCannon(sf::Sprite &sprite);
  sf::Vector2f getPosition() const;
  void draw(IRenderWindow &window) const;

private:
  sf::Vector2f position;
  sf::Sprite sprite;
};

#endif
