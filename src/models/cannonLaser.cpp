#include "../../include/models/cannonLaser.hpp"

CannonLaser::CannonLaser(ISprite *sprite, ISound *sound) : width_(6), height_(24), position_(sf::Vector2f(120, -24)), sprite_(sprite), sound_(sound)
{
  sprite_->setPosition(position_);
}

float CannonLaser::getWidth() const
{
  return width_;
}

float CannonLaser::getHeight() const
{
  return height_;
}

sf::Vector2f CannonLaser::getPosition() const
{
  return position_;
}

void CannonLaser::setPosition(const sf::Vector2f &vector)
{
  position_ = vector;
  sprite_->setPosition(position_);
}

void CannonLaser::draw(IRenderWindow &window) const
{
  if (position_.y > 0 - height_)
  {
    ISprite &rSprite = *sprite_;
    window.draw(rSprite);
  }
}

void CannonLaser::move()
{
  if (position_.y > 0 - height_)
  {
    position_.y -= 0.5;
    sprite_->setPosition(position_);
  }
}

void CannonLaser::reset()
{
  setPosition(sf::Vector2f(120, -24));
}

void CannonLaser::playInvaderDeath()
{
  sound_->play();
}
