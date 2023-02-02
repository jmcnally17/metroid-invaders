#ifndef LASER_CANNON_HPP
#define LASER_CANNON_HPP

#include <SFML/Graphics.hpp>

class LaserCannon
{
public:
  LaserCannon();
  sf::Vector2f getPosition() const;

private:
  sf::Vector2f position;
};

#endif
