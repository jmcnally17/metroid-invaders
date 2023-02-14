#ifndef LASER_CANNON_HPP
#define LASER_CANNON_HPP

#include "./iLaserCannon.hpp"
#include "../wrappers/iSprite.hpp"
#include "./iLaser.hpp"
#include "../wrappers/iSound.hpp"

class LaserCannon : public ILaserCannon
{
public:
  LaserCannon(ISprite *sprite, ILaser *laser, ISound *sound);
  float getWidth() const override;
  float getHeight() const override;
  void setPosition(const sf::Vector2f &vector);
  sf::Vector2f getPosition() const override;
  void draw(IRenderWindow &window) const override;
  void move(float x) override;
  void fire() override;
  void reset() override;

private:
  float width_;
  float height_;
  sf::Vector2f position_;
  ISprite *sprite_;
  ILaser *laser_;
  ISound *sound_;
};

#endif
