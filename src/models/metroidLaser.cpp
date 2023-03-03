#include "../../include/models/metroidLaser.hpp"

MetroidLaser::MetroidLaser(ISprite *sprite) : ILaser(18, 36, 120, 1344, sprite) {}

float MetroidLaser::getWidth() const
{
  return width_;
}

float MetroidLaser::getHeight() const
{
  return height_;
}

sf::Vector2f MetroidLaser::getPosition() const
{
  return position_;
}

void MetroidLaser::setPosition(const sf::Vector2f &position)
{
  position_ = position;
  sprite_->setPosition(position_);
}

void MetroidLaser::draw(IRenderWindow &window) const
{
  if (position_.y < 1344)
  {
    window.draw(*sprite_);
  }
}

void MetroidLaser::move()
{
  if (position_.y < 1344)
  {
    position_.y += 0.5;
    sprite_->setPosition(position_);
  }
}

void MetroidLaser::reset()
{
  setPosition(sf::Vector2f(120, 1344));
}

void MetroidLaser::playMetroidDeath() const {}
