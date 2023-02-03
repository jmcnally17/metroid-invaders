#include "../../include/models/laser.hpp"

Laser::Laser(ISprite &sprite) : width_(6), height_(24), position_(sf::Vector2f(120, -24)), sprite_(sprite)
{
  sprite_.setPosition(position_);
}

float Laser::getWidth() const
{
  return width_;
}

float Laser::getHeight() const
{
  return height_;
}

sf::Vector2f Laser::getPosition() const
{
  return position_;
}

void Laser::setPosition(const sf::Vector2f &vector)
{
  position_ = vector;
  sprite_.setPosition(position_);
}

void Laser::draw(IRenderWindow &window) const
{
  if (position_.y > 0 - height_)
  {
    window.draw(sprite_);
  }
}

void Laser::move()
{
  if (position_.y > 0 - height_)
  {
    position_.y -= 0.5;
    sprite_.setPosition(position_);
  }
}
