#include "../../include/models/ridley.hpp"

Ridley::Ridley(ISprite *sprite, ISound *movementSound) : IRidley(96, 42, -96, 200, sprite), points_(150), direction_(-1), movementSound_(movementSound)
{
  movementSound_->setLoop(true);
}

float Ridley::getWidth() const
{
  return width_;
}

float Ridley::getHeight() const
{
  return height_;
}

sf::Vector2f Ridley::getPosition() const
{
  return position_;
}

int Ridley::getPoints() const
{
  return points_;
}

int Ridley::getDirection() const
{
  return direction_;
}

void Ridley::setPosition(const sf::Vector2f &position)
{
  position_ = position;
  sprite_->setPosition(position_);
}

void Ridley::draw(IRenderWindow &window) const
{
  if (position_.x > -96 && position_.x < 1536)
  {
    ISprite &rSprite = *sprite_;
    window.draw(rSprite);
  }
}

void Ridley::changeDirection()
{
  direction_ *= -1;
}

void Ridley::reset()
{
  setPosition(sf::Vector2f(-96, 200));
  direction_ = -1;
}

void Ridley::move()
{
  if (position_.x > -96 && position_.x < 1536)
  {
    position_.x += 0.125 * direction_;
    sprite_->setPosition(position_);
  }
}

void Ridley::spawn(int randomNumber)
{
  if (randomNumber == 0 && (position_.x == -96 || position_.x == 1536))
  {
    changeDirection();
    position_.x += 0.125 * direction_;
    movementSound_->play();
  }
}

void Ridley::stopMovementSoundIfPlaying()
{
  if (movementSound_->getStatus() == sf::Sound::Playing)
  {
    movementSound_->stop();
  }
}

void Ridley::stopMovementSoundIfAtSideOfWindow()
{
  if (position_.x == -96 || position_.x == 1536)
  {
    stopMovementSoundIfPlaying();
  }
}

void Ridley::die()
{
  position_.x = 1536;
}
