#ifndef LASER_CANNON_HPP
#define LASER_CANNON_HPP

#include "./iLaserCannon.hpp"
#include "../wrappers/iSprite.hpp"
#include "./iLaser.hpp"

class LaserCannon : public ILaserCannon
{
public:
  LaserCannon(ISprite &sprite, ILaser &laser);
  float getWidth() const;
  void setPosition(const sf::Vector2f &vector);
  sf::Vector2f getPosition() const;
  void draw(IRenderWindow &window) const override;
  void move(float x) override;
  void fire();

private:
  float width_;
  sf::Vector2f position_;
  ISprite &sprite_;
  ILaser &laser_;
};

#endif
