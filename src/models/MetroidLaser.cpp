#include "../../include/Constants.hpp"
#include "../../include/models/MetroidLaser.hpp"

MetroidLaser::MetroidLaser(ISprite *sprite) : Laser(7.5 * Constants::lengthScale, 84 * Constants::lengthScale, sprite, 1) {}

sf::Vector2f MetroidLaser::getPosition() const
{
  return Laser::getPosition();
}

void MetroidLaser::setPosition(const sf::Vector2f &position)
{
  Laser::setPosition(position);
}

void MetroidLaser::draw(IRenderWindow &window) const
{
  if (getPosition().y < 84 * Constants::lengthScale)
  {
    Laser::draw(window);
  }
}

sf::FloatRect MetroidLaser::getGlobalBounds() const
{
  return Laser::getGlobalBounds();
}

bool MetroidLaser::intersects(const IGameObject &gameObject) const
{
  return Laser::intersects(gameObject);
}

void MetroidLaser::resetPosition()
{
  Laser::resetPosition();
}

void MetroidLaser::move()
{
  if (getPosition().y < 84 * Constants::lengthScale)
  {
    Laser::move();
  }
}
