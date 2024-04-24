#include "../../include/Constants.hpp"
#include "../../include/models/Gunship.hpp"

Gunship::Gunship(ISprite *sprite, IGunshipLaser *gunshipLaser, ISound *fireSound, ISound *deathSound)
    : MovingGameObject(7.5 * Constants::lengthScale, 76.5 * Constants::lengthScale, sprite, 0.2 * Constants::lengthScale), lives_(3), gunshipLaser_(gunshipLaser), fireSound_(fireSound), deathSound_(deathSound) {}

sf::Vector2f Gunship::getPosition() const
{
  return MovingGameObject::getPosition();
}

void Gunship::setPosition(const sf::Vector2f &position)
{
  MovingGameObject::setPosition(position);
}

void Gunship::draw(IRenderWindow &window) const
{
  MovingGameObject::draw(window);
}

sf::FloatRect Gunship::getGlobalBounds() const
{
  return MovingGameObject::getGlobalBounds();
}

bool Gunship::intersects(const IGameObject &gameObject) const
{
  return MovingGameObject::intersects(gameObject);
}

void Gunship::resetPosition()
{
  MovingGameObject::resetPosition();
}

int Gunship::getLives() const
{
  return lives_;
}

void Gunship::move(int direction)
{
  float velocity {speed_ * direction};
  if (getPosition().x + velocity >= 0 && getPosition().x + velocity <= 91.125 * Constants::lengthScale)
  {
    sprite_->move(sf::Vector2f(velocity, 0));
  }
}

void Gunship::fire()
{
  if (gunshipLaser_->getPosition().y <= -1.5 * Constants::lengthScale)
  {
    float startingXPosition {static_cast<float>(getPosition().x + (2.25 * Constants::lengthScale))};
    gunshipLaser_->setPosition(sf::Vector2f(startingXPosition, getPosition().y));
    fireSound_->play();
  }
}

void Gunship::loseLife()
{
  lives_--;
  deathSound_->play();
}

void Gunship::reset()
{
  resetPosition();
  lives_ = 3;
}
