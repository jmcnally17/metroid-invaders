#include "../../include/Constants.hpp"
#include "../../include/models/GunshipLaser.hpp"

GunshipLaser::GunshipLaser(ISprite *sprite) : Laser(7.5 * Constants::LENGTH_SCALE, -1.5 * Constants::LENGTH_SCALE, sprite, -1) {}

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
  if (getPosition().y > -1.5 * Constants::LENGTH_SCALE)
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
  if (getPosition().y > -1.5 * Constants::LENGTH_SCALE)
  {
    Laser::move();
  }
}
