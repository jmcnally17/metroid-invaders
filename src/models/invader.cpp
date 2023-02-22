#include "../../include/models/invader.hpp"

Invader::Invader(float width, float height, float x, float y, ISprite *sprite, int points) : IInvader(width, height, x, y, sprite),
                                                                                             originalPosition_(sf::Vector2f(x, y)),
                                                                                             points_(points),
                                                                                             alive_(true),
                                                                                             direction_(1),
                                                                                             justMovedDown_(false) {}

float Invader::getWidth() const
{
  return width_;
}

float Invader::getHeight() const
{
  return height_;
}

int Invader::getPoints() const
{
  return points_;
}

sf::Vector2f Invader::getOriginalPosition() const
{
  return originalPosition_;
}

sf::Vector2f Invader::getPosition() const
{
  return position_;
}

void Invader::setPosition(const sf::Vector2f &position)
{
  position_ = position;
  sprite_->setPosition(position_);
}

void Invader::draw(IRenderWindow &window) const
{
  ISprite &rSprite = *sprite_;
  window.draw(rSprite);
}

bool Invader::isAlive() const
{
  return alive_;
}

void Invader::die()
{
  alive_ = false;
}

int Invader::getDirection() const
{
  return direction_;
}

void Invader::move()
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

void Invader::changeDirection()
{
  direction_ *= -1;
}

bool Invader::hasJustMovedDown() const
{
  return justMovedDown_;
}

void Invader::resurrect()
{
  alive_ = true;
}

void Invader::reset()
{
  setPosition(originalPosition_);
  resurrect();
}

void Invader::shoot(const std::vector<ILaser *> &lasers, int randomNumber) const
{
  if (randomNumber == 0)
  {
    float xPosition = position_.x + (width_ / 2) - 9;
    float yPosition = position_.y + height_;
    sf::Vector2f newPosition(xPosition, yPosition);
    for (auto laser : lasers)
    {
      if (laser->getPosition().y >= 1344)
      {
        laser->setPosition(newPosition);
        return;
      }
    }
  }
}
