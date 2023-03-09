#include "../../include/models/bunker.hpp"

Bunker::Bunker(float x, float y, ISprite *sprite) : IBunker(144, 108, x, y, sprite), health_(10) {}

float Bunker::getWidth() const
{
  return width_;
}

float Bunker::getHeight() const
{
  return height_;
}

sf::Vector2f Bunker::getPosition() const
{
  return position_;
}

int Bunker::getHealth() const
{
  return health_;
}

void Bunker::decreaseHealth()
{
  health_--;
}

void Bunker::draw(IRenderWindow &window) const
{
  if (health_ > 0)
  {
    window.draw(*sprite_);
  }
}

void Bunker::reset()
{
  health_ = 10;
}

void Bunker::setPosition(const sf::Vector2f &position) {}