#include "../../include/models/laserCannon.hpp"

LaserCannon::LaserCannon(ISprite &sprite) : position_(sf::Vector2f(1416, 1224)), sprite_(sprite)
{
  sprite_.setPosition(position_);
}

sf::Vector2f LaserCannon::getPosition() const
{
  return position_;
}

void LaserCannon::draw(IRenderWindow &window) const
{
  window.draw(sprite_);
}
