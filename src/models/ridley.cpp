#include "../../include/models/ridley.hpp"

Ridley::Ridley(ISprite *sprite) : ObjectInterface(96, 42, -96, 200, sprite), points_(150) {}

float Ridley::getWidth() const
{
  return width_;
}

float Ridley::getHeight() const
{
  return height_;
}

sf::Vector2f Ridley::getPosition() const
{
  return position_;
}

int Ridley::getPoints() const
{
  return points_;
}

void Ridley::setPosition(const sf::Vector2f &position)
{
  position_ = position;
  sprite_->setPosition(position_);
}

void Ridley::draw(IRenderWindow &window) const
{
  ISprite &rSprite = *sprite_;
  window.draw(rSprite);
}

void Ridley::reset()
{
  setPosition(sf::Vector2f(-96, 200));
}
