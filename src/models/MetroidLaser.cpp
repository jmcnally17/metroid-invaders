#include "../../include/models/MetroidLaser.hpp"

MetroidLaser::MetroidLaser(ISprite *sprite) : Laser(120, 1344, sprite, 1) {}

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
  if (getPosition().y < 1344)
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
  if (getPosition().y < 1344)
  {
    Laser::move();
  }
}
