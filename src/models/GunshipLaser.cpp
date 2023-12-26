#include "../../include/models/GunshipLaser.hpp"

GunshipLaser::GunshipLaser(ISprite *sprite) : Laser(120, -24, sprite, -1) {}

sf::Vector2f GunshipLaser::getPosition() const
{
  return Laser::getPosition();
}

void GunshipLaser::setPosition(const sf::Vector2f &position)
{
  Laser::setPosition(position);
}

void GunshipLaser::draw(IRenderWindow &window) const
{
  if (getPosition().y > -24)
  {
    Laser::draw(window);
  }
}

sf::FloatRect GunshipLaser::getGlobalBounds() const
{
  return Laser::getGlobalBounds();
}

bool GunshipLaser::intersects(const IGameObject &gameObject) const
{
  return Laser::intersects(gameObject);
}

void GunshipLaser::resetPosition()
{
  Laser::resetPosition();
}

void GunshipLaser::move()
{
  if (getPosition().y > -24)
  {
    Laser::move();
  }
}
