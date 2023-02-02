#ifndef LASER_CANNON_HPP
#define LASER_CANNON_HPP

#include "./iLaserCannon.hpp"
#include "../wrappers/iSprite.hpp"

class LaserCannon : public ILaserCannon
{
public:
  LaserCannon(ISprite &sprite);
  sf::Vector2f getPosition() const;
  void draw(IRenderWindow &window) const;
  void move(float x);

private:
  sf::Vector2f position_;
  ISprite &sprite_;
};

#endif
