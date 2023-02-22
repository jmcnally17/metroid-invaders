#ifndef CANNON_LASER_HPP
#define CANNON_LASER_HPP

#include "./iLaser.hpp"
#include "../wrappers/iSound.hpp"

class CannonLaser : public ILaser
{
public:
  CannonLaser(ISprite *sprite, ISound *sound);
  float getWidth() const override;
  float getHeight() const override;
  sf::Vector2f getPosition() const override;
  void setPosition(const sf::Vector2f &position) override;
  void draw(IRenderWindow &window) const override;
  void move() override;
  void reset() override;
  void playInvaderDeath() const override;

private:
  ISound *sound_;
};

#endif
