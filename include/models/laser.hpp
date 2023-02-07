#ifndef LASER_HPP
#define LASER_HPP

#include "./iLaser.hpp"
#include "../wrappers/iSprite.hpp"
#include "../wrappers/iSound.hpp"
#include "../wrappers/iRenderWindow.hpp"

class Laser : public ILaser
{
public:
  Laser(ISprite &sprite, ISound &sound);
  float getWidth() const override;
  float getHeight() const override;
  sf::Vector2f getPosition() const override;
  void setPosition(const sf::Vector2f &vector) override;
  void draw(IRenderWindow &window) const override;
  void move() override;
  void reset() override;
  void playInvaderDeath() override;

private:
  float width_;
  float height_;
  sf::Vector2f position_;
  ISprite &sprite_;
  ISound &sound_;
};

#endif
