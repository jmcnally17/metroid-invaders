#include "../../include/models/Metroid.hpp"

Metroid::Metroid(float x, float y, ISprite *sprite, int points, ISound *deathSound)
    : Invader(x, y, sprite, 14.1, points, 1, deathSound), alive_(true), justMovedDown_(false) {}

sf::Vector2f Metroid::getPosition() const
{
  return MovingGameObject::getPosition();
}

void Metroid::setPosition(const sf::Vector2f &position)
{
  MovingGameObject::setPosition(position);
}

void Metroid::draw(IRenderWindow &window) const
{
  if (alive_)
  {
    MovingGameObject::draw(window);
  }
}

sf::FloatRect Metroid::getGlobalBounds() const
{
  return MovingGameObject::getGlobalBounds();
}

bool Metroid::intersects(const IGameObject &gameObject) const
{
  return MovingGameObject::intersects(gameObject);
}

sf::Vector2f Metroid::getOriginalPosition() const
{
  return Invader::getOriginalPosition();
}

int Metroid::getPoints() const
{
  return Invader::getPoints();
}

int Metroid::getDirection() const
{
  return Invader::getDirection();
}

void Metroid::changeDirection()
{
  Invader::changeDirection();
}

bool Metroid::isAlive() const
{
  return alive_;
}

bool Metroid::hasJustMovedDown() const
{
  return justMovedDown_;
}

void Metroid::move()
{
  float xDistanceCovered {getPosition().x - originalPosition_.x};
  bool isAtTheSide {abs(xDistanceCovered - 282) < 1e-3 || abs(xDistanceCovered + 282) < 1e-3};
  (!justMovedDown_ && isAtTheSide) ? moveDown() : moveAcross();
}

void Metroid::die()
{
  alive_ = false;
  Invader::die();
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

void Metroid::shoot(const std::array<IMetroidLaser*, 3> &metroidLasers, int randomNumber) const
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

void Metroid::moveDown()
{
  sprite_->move(sf::Vector2f(0, 42));
  justMovedDown_ = true;
  changeDirection();
}

void Metroid::moveAcross()
{
  Invader::move();
  if (justMovedDown_) {
    justMovedDown_ = false;
  }
}
