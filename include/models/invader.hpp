#ifndef INVADER_HPP
#define INVADER_HPP

#include <SFML/Graphics.hpp>

class Invader
{
public:
  Invader(float x, float y);
  sf::Vector2f getPosition() const;
  void setPosition(const sf::Vector2f &position);

private:
  sf::Vector2f position_;
};

#endif
