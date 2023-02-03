#include "../../include/models/laserCannon.hpp"

LaserCannon::LaserCannon(ISprite &sprite, ILaser &laser) : position_(sf::Vector2f(120, 1224)), sprite_(sprite), laser_(laser)
{
  width_ = 78;
  sprite_.setPosition(position_);
}

float LaserCannon::getWidth() const
{
  return width_;
}

void LaserCannon::setPosition(const sf::Vector2f &vector)
{
  position_ = vector;
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
  if (!((x < 0 && position_.x <= 0) || (x > 0 && position_.x >= 1536 - width_)))
  {
    position_.x += x;
    sprite_.setPosition(position_);
  }
}

void LaserCannon::fire()
{
  if (laser_.getPosition().y)
  {
    laser_.setPosition(sf::Vector2f(position_.x + (width_ - laser_.getWidth()) / 2, position_.y));
  }
}
