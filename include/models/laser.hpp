#ifndef LASER_HPP
#define LASER_HPP

#include <SFML/Graphics.hpp>

class Laser
{
public:
  Laser();
  sf::Vector2f getPosition() const;

private:
  sf::Vector2f position_;
};

#endif
