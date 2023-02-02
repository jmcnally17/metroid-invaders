#include "../../include/models/laserCannon.hpp"

LaserCannon::LaserCannon()
{
  position.x = 1416;
  position.y = 1224;
}

sf::Vector2f LaserCannon::getPosition() const
{
  return position;
}
