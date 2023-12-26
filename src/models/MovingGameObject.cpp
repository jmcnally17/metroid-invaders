#include "../../include/models/MovingGameObject.hpp"

MovingGameObject::MovingGameObject(float x, float y, ISprite *sprite, float speed) : GameObject(x, y, sprite), speed_(speed)
{
  originalPosition_ = sf::Vector2f(x, y);
}

sf::Vector2f MovingGameObject::getOriginalPosition() const
{
  return originalPosition_;
}

float MovingGameObject::getSpeed() const
{
  return speed_;
}

void MovingGameObject::resetPosition()
{
  setPosition(originalPosition_);
}
