#include "../../include/models/Ridley.hpp"

Ridley::Ridley(ISprite *rightSprite, ISound *deathSound, ISprite *leftSprite, ISound *movementSound)
    : Invader(-96, 200, rightSprite, 1.6, 150, -1, deathSound), leftSprite_(leftSprite), movementSound_(movementSound)
{
  leftSprite_->setPosition(sf::Vector2f(-96, 200));
  movementSound_->setLoop(true);
}

sf::Vector2f Ridley::getPosition() const
{
  return Invader::getPosition();
}

void Ridley::setPosition(const sf::Vector2f &position)
{
  Invader::setPosition(position);
  leftSprite_->setPosition(position);
}

void Ridley::draw(IRenderWindow &window) const
{
  float xPosition {getPosition().x};
  if (xPosition > -96 && xPosition < 1536)
  {
    direction_ == 1 ? Invader::draw(window) : window.draw(*leftSprite_);
  }
}

sf::FloatRect Ridley::getGlobalBounds() const
{
  return Invader::getGlobalBounds();
}

bool Ridley::intersects(const IGameObject &gameObject) const
{
  return Invader::intersects(gameObject);
}

int Ridley::getPoints() const
{
  return Invader::getPoints();
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

void Ridley::move()
{
  float xPosition {getPosition().x};
  if (xPosition > -96 && xPosition < 1536)
  {
    Invader::move();
    leftSprite_->move(sf::Vector2f(1.6 * direction_, 0));
  }
}

void Ridley::reset()
{
  setPosition(originalPosition_);
  direction_ = -1;
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
