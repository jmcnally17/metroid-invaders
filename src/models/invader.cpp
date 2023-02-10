#include "../../include/models/invader.hpp"

Invader::Invader(float x, float y, ISprite &sprite) : originalPosition_(sf::Vector2f(x, y)),
                                                      position_(sf::Vector2f(x, y)),
                                                      sprite_(sprite),
                                                      alive_(true),
                                                      direction_(1)
{
  sprite_.setPosition(position_);
}

sf::Vector2f Invader::getOriginalPosition() const
{
  return originalPosition_;
}

sf::Vector2f Invader::getPosition() const
{
  return position_;
}

void Invader::setPosition(const sf::Vector2f &position)
{
  position_ = position;
  sprite_.setPosition(position_);
}

void Invader::draw(IRenderWindow &window) const
{
  window.draw(sprite_);
}

bool Invader::isAlive() const
{
  return alive_;
}

void Invader::die()
{
  alive_ = false;
}

int Invader::getDirection() const
{
  return direction_;
}

void Invader::move()
{
  position_.x += 14.1 * direction_;
  sprite_.setPosition(position_);
}

void Invader::changeDirection()
{
  direction_ *= -1;
}
