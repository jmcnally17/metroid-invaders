#ifndef I_SPRITE_HPP
#define I_SPRITE_HPP

#include <SFML/Graphics.hpp>

class ISprite : public sf::Drawable
{
public:
  virtual void setPosition(const sf::Vector2f &position) = 0;
};

#endif
