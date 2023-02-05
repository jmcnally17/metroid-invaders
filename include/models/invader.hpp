#ifndef INVADER_HPP
#define INVADER_HPP

#include <SFML/Graphics.hpp>

class Invader
{
public:
  Invader(float x, float y);
  sf::Vector2f getPosition() const;

private:
  sf::Vector2f position_;
};

#endif
