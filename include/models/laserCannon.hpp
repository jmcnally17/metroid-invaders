#ifndef LASER_CANNON_HPP
#define LASER_CANNON_HPP

#include "./iLaserCannon.hpp"
#include "../wrappers/iSprite.hpp"

class LaserCannon : public ILaserCannon
{
public:
  LaserCannon(ISprite &sprite);
  float getWidth();
  void setPosition(sf::Vector2f vector);
  sf::Vector2f getPosition() const;
  void draw(IRenderWindow &window) const;
  void move(float x);

private:
  float width_;
  sf::Vector2f position_;
  ISprite &sprite_;
};

#endif
