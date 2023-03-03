#ifndef LASER_CANNON_HPP
#define LASER_CANNON_HPP

#include "./iLaserCannon.hpp"
#include "./iLaser.hpp"
#include "../wrappers/iSound.hpp"

class LaserCannon : public ILaserCannon
{
public:
  LaserCannon(ISprite *sprite, ILaser *cannonLaser, ISound *fireSound, ISound *deathSound);
  float getWidth() const override;
  float getHeight() const override;
  int getLives() const override;
  void setPosition(const sf::Vector2f &position) override;
  sf::Vector2f getPosition() const override;
  void draw(IRenderWindow &window) const override;
  void move(float x) override;
  void fire() override;
  void resetPosition() override;
  void reset() override;
  void loseLife() override;

private:
  int lives_;
  ILaser *cannonLaser_;
  ISound *fireSound_;
  ISound *deathSound_;
};

#endif
