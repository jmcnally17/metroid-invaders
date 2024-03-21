#include "../../include/models/Gunship.hpp"

Gunship::Gunship(ISprite *sprite, IGunshipLaser *gunshipLaser, ISound *fireSound, ISound *deathSound)
    : MovingGameObject(120, 1224, sprite, 3.2), lives_(3), gunshipLaser_(gunshipLaser), fireSound_(fireSound), deathSound_(deathSound) {}

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
  if (getPosition().x + velocity >= 0 && getPosition().x + velocity <= 1458)
  {
    sprite_->move(sf::Vector2f(velocity, 0));
  }
}

void Gunship::fire()
{
  if (gunshipLaser_->getPosition().y <= -24)
  {
    float startingXPosition {getPosition().x + 36};
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
