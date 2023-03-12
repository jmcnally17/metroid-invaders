#include "../../include/models/metroidLaser.hpp"

MetroidLaser::MetroidLaser(ISprite *sprite) : ILaser(120, 1344, sprite) {}

sf::Vector2f MetroidLaser::getPosition() const
{
  return sprite_->getPosition();
}

void MetroidLaser::setPosition(const sf::Vector2f &position)
{
  sprite_->setPosition(position);
}

void MetroidLaser::draw(IRenderWindow &window) const
{
  if (getPosition().y < 1344)
  {
    window.draw(*sprite_);
  }
}

void MetroidLaser::move()
{
  if (getPosition().y < 1344)
  {
    sprite_->move(sf::Vector2f(0, 6.4));
  }
}

void MetroidLaser::reset()
{
  setPosition(sf::Vector2f(120, 1344));
}

sf::FloatRect MetroidLaser::getGlobalBounds() const
{
  return sprite_->getGlobalBounds();
}

bool MetroidLaser::intersects(const sf::FloatRect &rectangle) const
{
  sf::FloatRect box = getGlobalBounds();
  return box.intersects(rectangle);
}

void MetroidLaser::playMetroidDeath() const {}
