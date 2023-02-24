#ifndef LASER_CANNON_HPP
#define LASER_CANNON_HPP

#include "./iLaserCannon.hpp"
#include "./iLaser.hpp"
#include "../wrappers/iSound.hpp"

class LaserCannon : public ILaserCannon
{
public:
  LaserCannon(ISprite *sprite, ILaser *laser, ISound *fireSound, ISound *deathSound);
  float getWidth() const override;
  float getHeight() const override;
  int getLives() const;
  void setPosition(const sf::Vector2f &position) override;
  sf::Vector2f getPosition() const override;
  void draw(IRenderWindow &window) const override;
  void move(float x) override;
  void fire() override;
  void resetPosition();
  void reset() override;
  void loseLife();

private:
  int lives_;
  ILaser *laser_;
  ISound *fireSound_;
  ISound *deathSound_;
};

#endif
