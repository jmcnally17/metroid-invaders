#include "../../include/Constants.hpp"
#include "../../include/models/Ridley.hpp"

Ridley::Ridley(ISprite *rightSprite, ISound *deathSound, ISprite *leftSprite, ISound *movementSound)
    : Invader(-6 * Constants::LENGTH_SCALE, 12.5 * Constants::LENGTH_SCALE, rightSprite, 0.1 * Constants::LENGTH_SCALE * Constants::FRAME_LENGTH / 6250, 150, -1, deathSound), leftSprite_(leftSprite), movementSound_(movementSound)
{
  leftSprite_->setPosition(sf::Vector2f(-6 * Constants::LENGTH_SCALE, 12.5 * Constants::LENGTH_SCALE));
  leftSprite_->setScale(sf::Vector2f(Constants::LENGTH_SCALE / 16, Constants::LENGTH_SCALE / 16));
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
  if (xPosition > -6 * Constants::LENGTH_SCALE && xPosition < 96 * Constants::LENGTH_SCALE)
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
  if (randomNumber == 0 && (xPosition <= -6 * Constants::LENGTH_SCALE || xPosition >= 96 * Constants::LENGTH_SCALE))
  {
    changeDirection();
    sprite_->move(sf::Vector2f(speed_ * direction_, 0));
    leftSprite_->move(sf::Vector2f(speed_ * direction_, 0));
    movementSound_->play();
  }
}

void Ridley::move()
{
  float xPosition {getPosition().x};
  if (xPosition > -6 * Constants::LENGTH_SCALE && xPosition < 96 * Constants::LENGTH_SCALE)
  {
    Invader::move();
    leftSprite_->move(sf::Vector2f(speed_ * direction_, 0));
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
  if (xPosition <= -6 * Constants::LENGTH_SCALE || xPosition >= 96 * Constants::LENGTH_SCALE)
  {
    stopMovementSoundIfPlaying();
  }
}

void Ridley::die()
{
  float newXPosition = direction_ == 1 ? 96 * Constants::LENGTH_SCALE : -6 * Constants::LENGTH_SCALE;
  setPosition(sf::Vector2f(newXPosition, 12.5 * Constants::LENGTH_SCALE));
  movementSound_->stop();
  deathSound_->play();
}
