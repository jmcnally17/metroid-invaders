#include "../../include/Constants.hpp"
#include "../../include/models/Bunker.hpp"

Bunker::Bunker(float x, float y, ISprite *sprite1, ISprite *sprite2, ISprite *sprite3, ISprite *sprite4, ISprite *sprite5)
    : GameObject(x, y, sprite1), sprite2_(sprite2), sprite3_(sprite3), sprite4_(sprite4), sprite5_(sprite5), health_(10)
{
  sf::Vector2f position = sf::Vector2f(x, y);
  sprite2_->setPosition(position);
  sprite3_->setPosition(position);
  sprite4_->setPosition(position);
  sprite5_->setPosition(position);
  sprite2_->setScale(sf::Vector2f(Constants::LENGTH_SCALE / 16, Constants::LENGTH_SCALE / 16));
  sprite3_->setScale(sf::Vector2f(Constants::LENGTH_SCALE / 16, Constants::LENGTH_SCALE / 16));
  sprite4_->setScale(sf::Vector2f(Constants::LENGTH_SCALE / 16, Constants::LENGTH_SCALE / 16));
  sprite5_->setScale(sf::Vector2f(Constants::LENGTH_SCALE / 16, Constants::LENGTH_SCALE / 16));
}

sf::Vector2f Bunker::getPosition() const
{
  return GameObject::getPosition();
}

void Bunker::setPosition(const sf::Vector2f &position)
{
  GameObject::setPosition(position);
}

sf::FloatRect Bunker::getGlobalBounds() const
{
  return GameObject::getGlobalBounds();
}

bool Bunker::intersects(const IGameObject &gameObject) const
{
  return GameObject::intersects(gameObject);
}

int Bunker::getHealth() const
{
  return health_;
}

void Bunker::decreaseHealth()
{
  health_--;
}

void Bunker::draw(IRenderWindow &window) const
{
  switch (health_)
  {
  case 10:
  case 9:
    window.draw(*sprite_);
    break;
  case 8:
  case 7:
    window.draw(*sprite2_);
    break;
  case 6:
  case 5:
    window.draw(*sprite3_);
    break;
  case 4:
  case 3:
    window.draw(*sprite4_);
    break;
  case 2:
  case 1:
    window.draw(*sprite5_);
    break;
  }
}

void Bunker::reset()
{
  health_ = 10;
}
