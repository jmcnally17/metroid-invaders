#include "../../include/models/ridley.hpp"

Ridley::Ridley(ISprite *rightSprite, ISprite *leftSprite, ISound *movementSound, ISound *deathSound)
    : IRidley(-96, 200, rightSprite), leftSprite_(leftSprite), points_(150), direction_(-1), movementSound_(movementSound), deathSound_(deathSound)
{
  leftSprite_->setPosition(sf::Vector2f(-96, 200));
  movementSound_->setLoop(true);
}

sf::Vector2f Ridley::getPosition() const
{
  return sprite_->getPosition();
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
  sprite_->setPosition(position);
  leftSprite_->setPosition(position);
}

void Ridley::draw(IRenderWindow &window) const
{
  float xPosition {getPosition().x};
  if (xPosition > -96 && xPosition < 1536)
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
  float xPosition {getPosition().x};
  if (xPosition > -96 && xPosition < 1536)
  {
    sprite_->move(sf::Vector2f(1.6 * direction_, 0));
    leftSprite_->move(sf::Vector2f(1.6 * direction_, 0));
  }
}

void Ridley::spawn(int randomNumber)
{
  float xPosition {getPosition().x};
  if (randomNumber == 0 && (xPosition <= -96 || xPosition >= 1536))
  {
    changeDirection();
    sprite_->move(sf::Vector2f(1.6 * direction_, 0));
    leftSprite_->move(sf::Vector2f(1.6 * direction_, 0));
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
  float xPosition {getPosition().x};
  if (xPosition <= -96 || xPosition >= 1536)
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

sf::FloatRect Ridley::getGlobalBounds() const
{
  return sprite_->getGlobalBounds();
}

bool Ridley::intersects(const sf::FloatRect &rectangle) const
{
  sf::FloatRect box {getGlobalBounds()};
  return box.intersects(rectangle);
}
