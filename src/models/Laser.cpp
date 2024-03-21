#include "../../include/models/Laser.hpp"

Laser::Laser(float x, float y, ISprite *sprite, int direction) : MovingGameObject(x, y, sprite, 6.4), direction_(direction) {}

int Laser::getDirection() const
{
  return direction_;
}

void Laser::move()
{
  sprite_->move(sf::Vector2f(0, speed_ * direction_));
}
