#ifndef METROID_LASER_HPP
#define METROID_LASER_HPP

#include "./Laser.hpp"
#include "./IMetroidLaser.hpp"

class MetroidLaser : public Laser, public IMetroidLaser
{
public:
  MetroidLaser(ISprite *sprite);
  sf::Vector2f getPosition() const override;
  void setPosition(const sf::Vector2f &position) override;
  void draw(IRenderWindow &window) const override;
  sf::FloatRect getGlobalBounds() const override;
  bool intersects(const IGameObject &gameObject) const override;
  void resetPosition() override;
  void move() override;
};

#endif
