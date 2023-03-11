#include "../../include/models/gunshipLaser.hpp"

GunshipLaser::GunshipLaser(ISprite *sprite, ISound *sound) : ILaser(6, 24, 120, -24, sprite), sound_(sound) {}

float GunshipLaser::getWidth() const
{
  return width_;
}

float GunshipLaser::getHeight() const
{
  return height_;
}

sf::Vector2f GunshipLaser::getPosition() const
{
  return position_;
}

void GunshipLaser::setPosition(const sf::Vector2f &position)
{
  position_ = position;
  sprite_->setPosition(position_);
}

void GunshipLaser::draw(IRenderWindow &window) const
{
  if (position_.y > 0 - height_)
  {
    window.draw(*sprite_);
  }
}

void GunshipLaser::move()
{
  if (position_.y > 0 - height_)
  {
    position_.y -= 6.4;
    sprite_->setPosition(position_);
  }
}

void GunshipLaser::reset()
{
  setPosition(sf::Vector2f(120, -24));
}

void GunshipLaser::playMetroidDeath() const
{
  sound_->play();
}
