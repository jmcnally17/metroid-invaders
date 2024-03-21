#include "../../include/models/GameObject.hpp"

GameObject::GameObject(float x, float y, ISprite *sprite) : sprite_(sprite)
{
  sprite_->setPosition(sf::Vector2f(x, y));
}

sf::Vector2f GameObject::getPosition() const
{
  return sprite_->getPosition();
}

void GameObject::setPosition(const sf::Vector2f &position)
{
  sprite_->setPosition(position);
}

void GameObject::draw(IRenderWindow &window) const
{
  window.draw(*sprite_);
}

sf::FloatRect GameObject::getGlobalBounds() const
{
  return sprite_->getGlobalBounds();
}

bool GameObject::intersects(const IGameObject &gameObject) const
{
  sf::FloatRect box1 {getGlobalBounds()};
  sf::FloatRect box2 {gameObject.getGlobalBounds()};
  return box1.intersects(box2);
}
