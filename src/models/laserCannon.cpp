#include "../../include/models/laserCannon.hpp"

LaserCannon::LaserCannon(ISprite *sprite, ILaser *laser, ISound *sound) : ILaserCannon(78, 48, 120, 1224, sprite),
                                                                          lives_(3),
                                                                          laser_(laser),
                                                                          sound_(sound) {}

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
  ISprite &rSprite = *sprite_;
  window.draw(rSprite);
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
  if (laser_->getPosition().y <= -laser_->getHeight())
  {
    float startingXPosition = position_.x + (width_ - laser_->getWidth()) / 2;
    laser_->setPosition(sf::Vector2f(startingXPosition, position_.y));
    sound_->play();
  }
}

void LaserCannon::resetPosition()
{
  setPosition(sf::Vector2f(120, 1224));
}

void LaserCannon::reset()
{
  resetPosition();
}
