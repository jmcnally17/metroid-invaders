#include "../../include/models/gunshipLaser.hpp"

GunshipLaser::GunshipLaser(ISprite *sprite, ISound *sound) : ILaser(120, -24, sprite), sound_(sound) {}

sf::Vector2f GunshipLaser::getPosition() const
{
  return sprite_->getPosition();
}

void GunshipLaser::setPosition(const sf::Vector2f &position)
{
  sprite_->setPosition(position);
}

void GunshipLaser::draw(IRenderWindow &window) const
{
  if (getPosition().y > -24)
  {
    window.draw(*sprite_);
  }
}

void GunshipLaser::move()
{
  if (getPosition().y > -24)
  {
    sprite_->move(sf::Vector2f(0, -6.4));
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

sf::FloatRect GunshipLaser::getGlobalBounds() const
{
  return sprite_->getGlobalBounds();
}

bool GunshipLaser::intersects(const sf::FloatRect &rectangle) const
{
  sf::FloatRect box {getGlobalBounds()};
  return box.intersects(rectangle);
}
