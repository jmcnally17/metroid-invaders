#include "../../include/models/ridley.hpp"

Ridley::Ridley(ISprite *rightSprite, ISprite *leftSprite, ISound *movementSound, ISound *deathSound)
    : IRidley(96, 42, -96, 200, rightSprite), leftSprite_(leftSprite), points_(150), direction_(-1), movementSound_(movementSound), deathSound_(deathSound)
{
  leftSprite_->setPosition(position_);
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
  updateSprites();
}

void Ridley::draw(IRenderWindow &window) const
{
  if (position_.x > -96 && position_.x < 1536)
  {
    direction_ == 1 ? window.draw(*sprite_) : window.draw(*leftSprite_);
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
    position_.x += 1.6 * direction_;
    updateSprites();
  }
}

void Ridley::spawn(int randomNumber)
{
  if (randomNumber == 0 && (position_.x <= -96 || position_.x >= 1536))
  {
    changeDirection();
    position_.x += 1.6 * direction_;
    updateSprites();
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
  if (position_.x <= -96 || position_.x >= 1536)
  {
    stopMovementSoundIfPlaying();
  }
}

void Ridley::die()
{
  float newXPosition = direction_ == 1 ? 1536 : -96;
  setPosition(sf::Vector2f(newXPosition, 200));
  movementSound_->stop();
  deathSound_->play();
}

void Ridley::updateSprites()
{
  sprite_->setPosition(position_);
  leftSprite_->setPosition(position_);
}
