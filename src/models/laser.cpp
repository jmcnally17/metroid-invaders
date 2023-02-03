#include "../../include/models/laser.hpp"

Laser::Laser(ISprite &sprite) : position_(sf::Vector2f(120, -24)), sprite_(sprite)
{
  sprite_.setPosition(position_);
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
  window.draw(sprite_);
}

void Laser::move()
{
  position_.y -= 0.5;
  sprite_.setPosition(position_);
}
