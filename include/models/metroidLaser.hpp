#ifndef METROID_LASER_HPP
#define METROID_LASER_HPP

#include "./iLaser.hpp"

class MetroidLaser : public ILaser
{
public:
  MetroidLaser(ISprite *sprite);
  float getWidth() const override;
  float getHeight() const override;
  sf::Vector2f getPosition() const override;
  void setPosition(const sf::Vector2f &position) override;
  void draw(IRenderWindow &window) const override;
  void move() override;
  void reset() override;
  sf::FloatRect getGlobalBounds() const override;
  bool intersects(const sf::FloatRect &rectangle) const override;

private:
  void playMetroidDeath() const override;
};

#endif
