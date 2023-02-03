#ifndef LASER_HPP
#define LASER_HPP

#include "../wrappers/iSprite.hpp"
#include "../wrappers/iRenderWindow.hpp"

class Laser
{
public:
  Laser(ISprite &sprite);
  float getWidth() const;
  float getHeight() const;
  sf::Vector2f getPosition() const;
  void setPosition(const sf::Vector2f &vector);
  void draw(IRenderWindow &window) const;
  void move();

private:
  float width_;
  float height_;
  sf::Vector2f position_;
  ISprite &sprite_;
};

#endif
