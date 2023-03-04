#include "../../include/models/metroid.hpp"

Metroid::Metroid(float width, float height, float x, float y, ISprite *sprite, int points) : IMetroid(width, height, x, y, sprite),
                                                                                             originalPosition_(sf::Vector2f(x, y)),
                                                                                             points_(points),
                                                                                             alive_(true),
                                                                                             direction_(1),
                                                                                             justMovedDown_(false) {}

float Metroid::getWidth() const
{
  return width_;
}

float Metroid::getHeight() const
{
  return height_;
}

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
  return position_;
}

void Metroid::setPosition(const sf::Vector2f &position)
{
  position_ = position;
  sprite_->setPosition(position_);
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
  if (!justMovedDown_ && (abs(position_.x - originalPosition_.x - 282) < 1e-3 || abs(position_.x - originalPosition_.x + 282) < 1e-3))
  {
    position_.y += 42;
    justMovedDown_ = true;
    changeDirection();
  }
  else
  {
    position_.x += 14.1 * direction_;
    justMovedDown_ = false;
  }
  sprite_->setPosition(position_);
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
}

void Metroid::shoot(const std::vector<ILaser *> &metroidLasers, int randomNumber) const
{
  if (randomNumber == 0)
  {
    float xPosition = position_.x + (width_ / 2) - 9;
    float yPosition = position_.y + height_;
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
