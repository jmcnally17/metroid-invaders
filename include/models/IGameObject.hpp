#ifndef I_GAME_OBJECT_HPP
#define I_GAME_OBJECT_HPP

#include <SFML/Graphics.hpp>
#include "../adaptors/ISprite.hpp"
#include "../adaptors/IRenderWindow.hpp"

class IGameObject
{
public:
  virtual sf::Vector2f getPosition() const = 0;
  virtual void setPosition(const sf::Vector2f &position) = 0;
  virtual void draw(IRenderWindow &window) const = 0;
  virtual sf::FloatRect getGlobalBounds() const = 0;
  virtual bool intersects(const IGameObject &gameObject) const = 0;
};

#endif
