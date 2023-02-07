#include "../../include/models/invader.hpp"

Invader::Invader(float x, float y, ISprite &sprite) : position_(sf::Vector2f(x, y)), sprite_(sprite), alive_(true)
{
  sprite_.setPosition(position_);
}

sf::Vector2f Invader::getPosition() const
{
  return position_;
}

void Invader::setPosition(const sf::Vector2f &position)
{
  position_ = position;
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
