#ifndef I_SPRITE_HPP
#define I_SPRITE_HPP

#include <SFML/Graphics.hpp>

class ISprite : virtual public sf::Drawable
{
public:
  virtual void setPosition(const sf::Vector2f &position) = 0;
  virtual void setScale(float factorX, float factorY) = 0;
};

#endif
