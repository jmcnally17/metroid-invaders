#ifndef LASER_HPP
#define LASER_HPP

#include "./iLaser.hpp"
#include "../wrappers/iSprite.hpp"
#include "../wrappers/iRenderWindow.hpp"

class Laser : public ILaser
{
public:
  Laser();
  float getWidth() const override;
  float getHeight() const override;
  sf::Vector2f getPosition() const override;
  void setPosition(const sf::Vector2f &vector) override;
  void draw(IRenderWindow &window) const override;
  void move() override;

private:
  float width_;
  float height_;
  sf::Vector2f position_;
  sf::Texture texture_;
  sf::Sprite sprite_;
};

#endif
