#ifndef INVADER_LASER_HPP
#define INVADER_LASER_HPP

#include "./iLaser.hpp"

class InvaderLaser : public ILaser
{
public:
  InvaderLaser(ISprite *sprite);
  float getWidth() const override;
  float getHeight() const override;
  sf::Vector2f getPosition() const override;
  void setPosition(const sf::Vector2f &position) override;
  void draw(IRenderWindow &window) const override;
  void move() override;
  void reset() override;
  void playInvaderDeath() const override;
};

#endif
