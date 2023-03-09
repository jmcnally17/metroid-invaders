#include "../../include/models/bunker.hpp"

Bunker::Bunker(float x, float y, ISprite *sprite1, ISprite *sprite2, ISprite *sprite3, ISprite *sprite4, ISprite *sprite5)
    : IBunker(144, 108, x, y, sprite1), health_(10), sprite2_(sprite2), sprite3_(sprite3), sprite4_(sprite4), sprite5_(sprite5)
{
  sprite2_->setPosition(position_);
  sprite3_->setPosition(position_);
  sprite4_->setPosition(position_);
  sprite5_->setPosition(position_);
}

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
