#include "../../include/models/laserCannon.hpp"

LaserCannon::LaserCannon(ISprite &sprite) : position_(sf::Vector2f(120, 1224)), sprite_(sprite)
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

void LaserCannon::move(float x)
{
  position_.x += x;
  sprite_.setPosition(position_);
}
