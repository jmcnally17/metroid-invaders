#include "../../include/models/metroid.hpp"

Metroid::Metroid(float x, float y, ISprite *sprite, int points)
    : IMetroid(x, y, sprite), originalPosition_(sf::Vector2f(x, y)), points_(points), alive_(true), direction_(1), justMovedDown_(false) {}

int Metroid::getPoints() const
{
  return points_;
}

sf::Vector2f Metroid::getOriginalPosition() const
{
  return originalPosition_;
}

sf::Vector2f Metroid::getPosition() const
{
  return sprite_->getPosition();
}

void Metroid::setPosition(const sf::Vector2f &position)
{
  sprite_->setPosition(position);
}

void Metroid::draw(IRenderWindow &window) const
{
  window.draw(*sprite_);
}

bool Metroid::isAlive() const
{
  return alive_;
}

void Metroid::die()
{
  alive_ = false;
}

int Metroid::getDirection() const
{
  return direction_;
}

void Metroid::move()
{
  float xDistanceCovered {getPosition().x - originalPosition_.x};
  bool isAtTheSide {abs(xDistanceCovered - 282) < 1e-3 || abs(xDistanceCovered + 282) < 1e-3};
  (!justMovedDown_ && isAtTheSide) ? moveDown() : moveAcross();
}

void Metroid::changeDirection()
{
  direction_ *= -1;
}

bool Metroid::hasJustMovedDown() const
{
  return justMovedDown_;
}

void Metroid::resurrect()
{
  alive_ = true;
}

void Metroid::reset()
{
  setPosition(originalPosition_);
  resurrect();
  direction_ = 1;
}

void Metroid::shoot(const std::array<ILaser*, 3> &metroidLasers, int randomNumber) const
{
  if (randomNumber == 0)
  {
    sf::FloatRect bounds {getGlobalBounds()};
    float xPosition {getPosition().x + (bounds.width / 2) - 9};
    float yPosition {getPosition().y + bounds.height};
    sf::Vector2f newPosition(xPosition, yPosition);
    for (auto metroidLaser : metroidLasers)
    {
      if (metroidLaser->getPosition().y >= 1344)
      {
        metroidLaser->setPosition(newPosition);
        return;
      }
    }
  }
}

sf::FloatRect Metroid::getGlobalBounds() const
{
  return sprite_->getGlobalBounds();
}

bool Metroid::intersects(const sf::FloatRect &rectangle) const
{
  sf::FloatRect box {getGlobalBounds()};
  return box.intersects(rectangle);
}

void Metroid::moveDown()
{
  sprite_->move(sf::Vector2f(0, 42));
  justMovedDown_ = true;
  changeDirection();
}

void Metroid::moveAcross()
{
  sprite_->move(sf::Vector2f(14.1 * direction_, 0));
  justMovedDown_ = false;
}
