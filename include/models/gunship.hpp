#ifndef GUNSHIP_HPP
#define GUNSHIP_HPP

#include "./iGunship.hpp"
#include "./iLaser.hpp"
#include "../wrappers/iSound.hpp"

class Gunship : public IGunship
{
public:
  Gunship(ISprite *sprite, ILaser *gunshipLaser, ISound *fireSound, ISound *deathSound);
  float getWidth() const override;
  float getHeight() const override;
  int getLives() const override;
  void setPosition(const sf::Vector2f &position) override;
  sf::Vector2f getPosition() const override;
  void draw(IRenderWindow &window) const override;
  void move(float x) override;
  void fire() override;
  void resetPosition() override;
  void reset() override;
  void loseLife() override;
  sf::FloatRect getGlobalBounds() const override;
  bool intersects(const sf::FloatRect &rectangle) const override;

private:
  int lives_;
  ILaser *gunshipLaser_;
  ISound *fireSound_;
  ISound *deathSound_;
};

#endif
