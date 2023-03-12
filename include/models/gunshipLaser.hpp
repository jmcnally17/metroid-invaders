#ifndef GUNSHIP_LASER_HPP
#define GUNSHIP_LASER_HPP

#include "./iLaser.hpp"
#include "../wrappers/iSound.hpp"

class GunshipLaser : public ILaser
{
public:
  GunshipLaser(ISprite *sprite, ISound *sound);
  sf::Vector2f getPosition() const override;
  void setPosition(const sf::Vector2f &position) override;
  void draw(IRenderWindow &window) const override;
  void move() override;
  void reset() override;
  void playMetroidDeath() const override;
  sf::FloatRect getGlobalBounds() const override;
  bool intersects(const sf::FloatRect &rectangle) const override;

private:
  ISound *sound_;
};

#endif
