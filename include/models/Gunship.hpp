#ifndef GUNSHIP_HPP
#define GUNSHIP_HPP

#include "./MovingGameObject.hpp"
#include "./IGunship.hpp"
#include "./IGunshipLaser.hpp"
#include "../wrappers/ISound.hpp"

class Gunship : public MovingGameObject, public IGunship
{
public:
  Gunship(ISprite *sprite, IGunshipLaser *gunshipLaser, ISound *fireSound, ISound *deathSound);
  sf::Vector2f getPosition() const override;
  void setPosition(const sf::Vector2f &position) override;
  void draw(IRenderWindow &window) const override;
  sf::FloatRect getGlobalBounds() const override;
  bool intersects(const IGameObject &gameObject) const override;
  void resetPosition() override;
  int getLives() const override;
  void move(int direction) override;
  void fire() override;
  void loseLife() override;
  void reset() override;

private:
  int lives_;
  IGunshipLaser *gunshipLaser_;
  ISound *fireSound_;
  ISound *deathSound_;
};

#endif
