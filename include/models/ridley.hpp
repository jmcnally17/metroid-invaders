#ifndef RIDLEY_HPP
#define RIDLEY_HPP

#include "./iRidley.hpp"
#include "../wrappers/iSound.hpp"

class Ridley : public IRidley
{
public:
  Ridley(ISprite *sprite, ISound *movementSound, ISound *deathSound);
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
  void spawn(int randomNumber = rand() % 10000) override;
  void stopMovementSoundIfPlaying() override;
  void stopMovementSoundIfAtSideOfWindow() override;
  void die();

private:
  int points_;
  int direction_;
  ISound *movementSound_;
  ISound *deathSound_;
};

#endif
