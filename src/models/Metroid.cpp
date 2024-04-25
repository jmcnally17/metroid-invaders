#include "../../include/Constants.hpp"
#include "../../include/models/Metroid.hpp"

Metroid::Metroid(float x, float y, ISprite *sprite, int points, ISound *deathSound)
    : Invader(x, y, sprite, 0.88125 * Constants::LENGTH_SCALE, points, 1, deathSound), alive_(true), justMovedDown_(false) {}

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
  bool isAtTheSide {abs(xDistanceCovered - (17.625 * Constants::LENGTH_SCALE)) < 1e-3 || abs(xDistanceCovered + (17.625 * Constants::LENGTH_SCALE)) < 1e-3};
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
    float xPosition {static_cast<float>(getPosition().x + (bounds.width / 2) - (0.5625 * Constants::LENGTH_SCALE))};
    float yPosition {getPosition().y + bounds.height};
    sf::Vector2f newPosition(xPosition, yPosition);
    for (auto metroidLaser : metroidLasers)
    {
      if (metroidLaser->getPosition().y >= 84 * Constants::LENGTH_SCALE)
      {
        metroidLaser->setPosition(newPosition);
        return;
      }
    }
  }
}

void Metroid::moveDown()
{
  sprite_->move(sf::Vector2f(0, 2.625 * Constants::LENGTH_SCALE));
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
