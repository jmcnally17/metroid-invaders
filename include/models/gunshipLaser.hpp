#ifndef GUNSHIP_LASER_HPP
#define GUNSHIP_LASER_HPP

#include "./iLaser.hpp"
#include "../wrappers/iSound.hpp"

class GunshipLaser : public ILaser
{
public:
  GunshipLaser(ISprite *sprite, ISound *sound);
  float getWidth() const override;
  float getHeight() const override;
  sf::Vector2f getPosition() const override;
  void setPosition(const sf::Vector2f &position) override;
  void draw(IRenderWindow &window) const override;
  void move() override;
  void reset() override;
  void playMetroidDeath() const override;

private:
  ISound *sound_;
};

#endif
