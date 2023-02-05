#ifndef LASER_CANNON_HPP
#define LASER_CANNON_HPP

#include "./iLaserCannon.hpp"
#include "./iLaser.hpp"
#include <SFML/Audio.hpp>

class LaserCannon : public ILaserCannon
{
public:
  LaserCannon(ILaser &laser);
  float getWidth() const;
  float getHeight() const;
  void setPosition(const sf::Vector2f &vector);
  sf::Vector2f getPosition() const;
  void draw(IRenderWindow &window) const override;
  void move(float x) override;
  void fire() override;

private:
  float width_;
  float height_;
  sf::Vector2f position_;
  sf::Texture texture_;
  sf::Sprite sprite_;
  ILaser &laser_;
  sf::SoundBuffer buffer_;
  sf::Sound sound_;
};

#endif
