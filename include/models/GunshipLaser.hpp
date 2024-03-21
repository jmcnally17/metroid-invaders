#ifndef GUNSHIP_LASER_HPP
#define GUNSHIP_LASER_HPP

#include "./Laser.hpp"
#include "./IGunshipLaser.hpp"

class GunshipLaser : public Laser, public IGunshipLaser
{
public:
  GunshipLaser(ISprite *sprite);
  sf::Vector2f getPosition() const override;
  void setPosition(const sf::Vector2f &position) override;
  void draw(IRenderWindow &window) const override;
  sf::FloatRect getGlobalBounds() const override;
  bool intersects(const IGameObject &gameObject) const override;
  void resetPosition() override;
  void move() override;
};

#endif
