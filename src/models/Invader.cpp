#include "../../include/models/Invader.hpp"

Invader::Invader(float x, float y, ISprite *sprite, float speed, int points, int direction, ISound *deathSound) : MovingGameObject(x, y, sprite, speed), points_(points), direction_(direction), deathSound_(deathSound) {}

int Invader::getPoints() const
{
  return points_;
}

int Invader::getDirection() const
{
  return direction_;
}

void Invader::changeDirection()
{
  direction_ *= -1;
}

void Invader::move()
{
  sprite_->move(sf::Vector2f(speed_ * direction_, 0));
}

void Invader::die()
{
  deathSound_->play();
}
