#ifndef I_TEXT_HPP
#define I_TEXT_HPP

#include <SFML/Graphics.hpp>

class IText : virtual public sf::Drawable
{
public:
  virtual void setString(const std::string &string) = 0;
  virtual void setPosition(const sf::Vector2f &position) = 0;
};

#endif
