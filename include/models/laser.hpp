#ifndef LASER_HPP
#define LASER_HPP

#include "./iLaser.hpp"
#include "../wrappers/iSprite.hpp"
#include "../wrappers/iRenderWindow.hpp"

class Laser : public ILaser
{
public:
  Laser(ISprite &sprite);
  float getWidth() const override;
  float getHeight() const override;
  sf::Vector2f getPosition() const override;
  void setPosition(const sf::Vector2f &vector) override;
  void draw(IRenderWindow &window) const override;
  void move();

private:
  float width_;
  float height_;
  sf::Vector2f position_;
  ISprite &sprite_;
};

#endif
