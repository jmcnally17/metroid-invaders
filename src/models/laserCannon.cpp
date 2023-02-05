#include "../../include/models/laserCannon.hpp"

LaserCannon::LaserCannon(ILaser &laser) : width_(78), height_(48), position_(sf::Vector2f(120, 1224)), laser_(laser)
{
  texture_.loadFromFile("public/images/newSprites/laserCannon.png");
  sprite_.setTexture(texture_);
  sprite_.setPosition(position_);
  buffer_.loadFromFile("public/audio/shoot.wav");
  sound_.setBuffer(buffer_);
}

float LaserCannon::getWidth() const
{
  return width_;
}

float LaserCannon::getHeight() const
{
  return height_;
}

void LaserCannon::setPosition(const sf::Vector2f &vector)
{
  position_ = vector;
  sprite_.setPosition(position_);
}

sf::Vector2f LaserCannon::getPosition() const
{
  return position_;
}

void LaserCannon::draw(IRenderWindow &window) const
{
  window.draw(sprite_);
}

void LaserCannon::move(float x)
{
  if (!((x < 0 && position_.x <= 0) || (x > 0 && position_.x >= 1536 - width_)))
  {
    position_.x += x;
    sprite_.setPosition(position_);
  }
}

void LaserCannon::fire()
{
  if (laser_.getPosition().y <= -laser_.getHeight())
  {
    float startingXPosition = position_.x + (width_ - laser_.getWidth()) / 2;
    laser_.setPosition(sf::Vector2f(startingXPosition, position_.y));
    sound_.play();
  }
}
