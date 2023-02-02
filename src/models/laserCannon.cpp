#include "../../include/models/laserCannon.hpp"

LaserCannon::LaserCannon(ISprite &sprite) : position_(sf::Vector2f(120, 1224)), sprite_(sprite)
{
  width_ = 78;
  sprite_.setPosition(position_);
}

float LaserCannon::getWidth()
{
  return width_;
}

void LaserCannon::setPosition(sf::Vector2f vector)
{
  position_ = vector;
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
  if (!((x < 0 && position_.x <= 0) || (x > 0 && position_.x >= 1536 - width_)))
  {
    position_.x += x;
    sprite_.setPosition(position_);
  }
}
