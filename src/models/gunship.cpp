#include "../../include/models/gunship.hpp"

Gunship::Gunship(ISprite *sprite, ILaser *gunshipLaser, ISound *fireSound, ISound *deathSound)
    : IGunship(78, 45, 120, 1224, sprite), lives_(3), gunshipLaser_(gunshipLaser), fireSound_(fireSound), deathSound_(deathSound) {}

float Gunship::getWidth() const
{
  return width_;
}

float Gunship::getHeight() const
{
  return height_;
}

int Gunship::getLives() const
{
  return lives_;
}

void Gunship::setPosition(const sf::Vector2f &position)
{
  position_ = position;
  sprite_->setPosition(position_);
}

sf::Vector2f Gunship::getPosition() const
{
  return position_;
}

void Gunship::draw(IRenderWindow &window) const
{
  window.draw(*sprite_);
}

void Gunship::move(float x)
{
  if (!((x < 0 && position_.x <= 0) || (x > 0 && position_.x >= 1536 - width_)))
  {
    position_.x += x;
    sprite_->setPosition(position_);
  }
}

void Gunship::fire()
{
  if (gunshipLaser_->getPosition().y <= -gunshipLaser_->getHeight())
  {
    float startingXPosition = position_.x + (width_ - gunshipLaser_->getWidth()) / 2;
    gunshipLaser_->setPosition(sf::Vector2f(startingXPosition, position_.y));
    fireSound_->play();
  }
}

void Gunship::resetPosition()
{
  setPosition(sf::Vector2f(120, 1224));
}

void Gunship::reset()
{
  resetPosition();
  lives_ = 3;
}

void Gunship::loseLife()
{
  lives_--;
  deathSound_->play();
}
