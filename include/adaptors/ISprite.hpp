#ifndef I_SPRITE_HPP
#define I_SPRITE_HPP

#include <SFML/Graphics.hpp>

class ISprite : virtual public sf::Drawable
{
public:
  virtual sf::Vector2f getPosition() const = 0;
  virtual void setPosition(const sf::Vector2f &position) = 0;
  virtual void move(const sf::Vector2f &offset) = 0;
  virtual sf::FloatRect getGlobalBounds() const = 0;
};

#endif
