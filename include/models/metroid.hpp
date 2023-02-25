#ifndef METROID_HPP
#define METROID_HPP

#include "./iMetroid.hpp"

class Metroid : public IMetroid
{
public:
  Metroid(float width, float height, float x, float y, ISprite *sprite, int points);
  float getWidth() const override;
  float getHeight() const override;
  int getPoints() const override;
  sf::Vector2f getOriginalPosition() const override;
  sf::Vector2f getPosition() const override;
  void setPosition(const sf::Vector2f &position) override;
  void draw(IRenderWindow &window) const override;
  bool isAlive() const override;
  void die() override;
  int getDirection() const override;
  void move() override;
  void changeDirection() override;
  bool hasJustMovedDown() const override;
  void resurrect() override;
  void reset() override;
  void shoot(const std::vector<ILaser *> &lasers, int randomNumber = rand() % 100000) const override;

private:
  sf::Vector2f originalPosition_;
  int points_;
  bool alive_;
  int direction_;
  bool justMovedDown_;
};

#endif