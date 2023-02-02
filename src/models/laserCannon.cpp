#include "../../include/models/laserCannon.hpp"

LaserCannon::LaserCannon(sf::Sprite &sprite) : position(sf::Vector2f(1416, 1224)), sprite(sprite) {}

sf::Vector2f LaserCannon::getPosition() const
{
  return position;
}

void LaserCannon::draw(IRenderWindow &window) const
{
  window.draw(sprite);
}
