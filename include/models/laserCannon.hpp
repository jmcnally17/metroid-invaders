#ifndef LASER_CANNON_HPP
#define LASER_CANNON_HPP

#include "./iLaserCannon.hpp"
#include "../wrappers/iSprite.hpp"

class LaserCannon : public ILaserCannon
{
public:
  LaserCannon(ISprite &sprite);
  float getWidth() const;
  void setPosition(const sf::Vector2f &vector);
  sf::Vector2f getPosition() const override;
  void draw(IRenderWindow &window) const override;
  void move(float x) override;

private:
  float width_;
  sf::Vector2f position_;
  ISprite &sprite_;
};

#endif
