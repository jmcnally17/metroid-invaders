#include "../../include/models/laserCannon.hpp"

LaserCannon::LaserCannon(ISprite *sprite, ILaser *cannonLaser, ISound *fireSound, ISound *deathSound) : ILaserCannon(78, 48, 120, 1224, sprite),
                                                                                                        lives_(3),
                                                                                                        cannonLaser_(cannonLaser),
                                                                                                        fireSound_(fireSound),
                                                                                                        deathSound_(deathSound) {}

float LaserCannon::getWidth() const
{
  return width_;
}

float LaserCannon::getHeight() const
{
  return height_;
}

int LaserCannon::getLives() const
{
  return lives_;
}

void LaserCannon::setPosition(const sf::Vector2f &position)
{
  position_ = position;
  sprite_->setPosition(position_);
}

sf::Vector2f LaserCannon::getPosition() const
{
  return position_;
}

void LaserCannon::draw(IRenderWindow &window) const
{
  window.draw(*sprite_);
}

void LaserCannon::move(float x)
{
  if (!((x < 0 && position_.x <= 0) || (x > 0 && position_.x >= 1536 - width_)))
  {
    position_.x += x;
    sprite_->setPosition(position_);
  }
}

void LaserCannon::fire()
{
  if (cannonLaser_->getPosition().y <= -cannonLaser_->getHeight())
  {
    float startingXPosition = position_.x + (width_ - cannonLaser_->getWidth()) / 2;
    cannonLaser_->setPosition(sf::Vector2f(startingXPosition, position_.y));
    fireSound_->play();
  }
}

void LaserCannon::resetPosition()
{
  setPosition(sf::Vector2f(120, 1224));
}

void LaserCannon::reset()
{
  resetPosition();
  lives_ = 3;
}

void LaserCannon::loseLife()
{
  lives_--;
  deathSound_->play();
}
