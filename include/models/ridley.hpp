#ifndef RIDLEY_HPP
#define RIDLEY_HPP

#include "./iRidley.hpp"

class Ridley : public IRidley
{
public:
  Ridley(ISprite *sprite);
  float getWidth() const override;
  float getHeight() const override;
  sf::Vector2f getPosition() const override;
  int getPoints() const;
  int getDirection() const;
  void setPosition(const sf::Vector2f &position) override;
  void draw(IRenderWindow &window) const override;
  void changeDirection();
  void reset() override;
  void move() override;
  void spawn(int randomNumber = rand() % 1000) override;

private:
  int points_;
  int direction_;
};

#endif
