#include "../../include/models/gunship.hpp"

Gunship::Gunship(ISprite *sprite, ILaser *gunshipLaser, ISound *fireSound, ISound *deathSound)
    : IGunship(120, 1224, sprite), lives_(3), gunshipLaser_(gunshipLaser), fireSound_(fireSound), deathSound_(deathSound) {}

int Gunship::getLives() const
{
  return lives_;
}

void Gunship::setPosition(const sf::Vector2f &position)
{
  sprite_->setPosition(position);
}

sf::Vector2f Gunship::getPosition() const
{
  return sprite_->getPosition();
}

void Gunship::draw(IRenderWindow &window) const
{
  window.draw(*sprite_);
}

void Gunship::move(float x)
{
  if (!((x < 0 && getPosition().x <= 0) || (x > 0 && getPosition().x >= 1458)))
  {
    sprite_->move(sf::Vector2f(x, 0));
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

sf::FloatRect Gunship::getGlobalBounds() const
{
  return sprite_->getGlobalBounds();
}

bool Gunship::intersects(const sf::FloatRect &rectangle) const
{
  sf::FloatRect box {getGlobalBounds()};
  return box.intersects(rectangle);
}
