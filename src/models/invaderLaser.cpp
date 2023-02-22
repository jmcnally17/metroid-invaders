#include "../../include/models/invaderLaser.hpp"

InvaderLaser::InvaderLaser(ISprite *sprite) : ILaser(18, 36, 120, 1344, sprite) {}

float InvaderLaser::getWidth() const
{
  return width_;
}

float InvaderLaser::getHeight() const
{
  return height_;
}

sf::Vector2f InvaderLaser::getPosition() const
{
  return position_;
}

void InvaderLaser::setPosition(const sf::Vector2f &position)
{
  position_ = position;
  sprite_->setPosition(position_);
}

void InvaderLaser::draw(IRenderWindow &window) const
{
  if (position_.y < 1344)
  {
    ISprite &rSprite = *sprite_;
    window.draw(rSprite);
  }
}

void InvaderLaser::move()
{
  if (position_.y < 1344)
  {
    position_.y += 0.5;
    sprite_->setPosition(position_);
  }
}

void InvaderLaser::reset()
{
  setPosition(sf::Vector2f(120, 1344));
}

void InvaderLaser::playInvaderDeath() const {}
