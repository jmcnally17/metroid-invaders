#ifndef METROID_HPP
#define METROID_HPP

#include "./Invader.hpp"
#include "./IMetroid.hpp"
#include "../adaptors/ISound.hpp"

class Metroid : public Invader, public IMetroid
{
public:
  Metroid(float x, float y, ISprite *sprite, int points, ISound *deathSound);
  sf::Vector2f getPosition() const override;
  void setPosition(const sf::Vector2f &position) override;
  void draw(IRenderWindow &window) const override;
  sf::FloatRect getGlobalBounds() const override;
  bool intersects(const IGameObject &gameObject) const override;
  sf::Vector2f getOriginalPosition() const override;
  int getPoints() const override;
  int getDirection() const override;
  void changeDirection() override;
  bool isAlive() const override;
  bool hasJustMovedDown() const override;
  void move() override;
  void die() override;
  void resurrect() override;
  void reset() override;
  void shoot(const std::array<IMetroidLaser*, 3> &metroidLasers, int randomNumber = rand() % 10000) const override;

private:
  bool alive_;
  bool justMovedDown_;
  void moveAcross() override;
  void moveDown() override;
};

#endif
