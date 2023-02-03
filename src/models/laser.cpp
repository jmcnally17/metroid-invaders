#include "../../include/models/laser.hpp"

Laser::Laser()
{
  position_ = sf::Vector2f(120, -24);
}

sf::Vector2f Laser::getPosition() const
{
  return position_;
}
