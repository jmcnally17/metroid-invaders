#ifndef RIDLEY_HPP
#define RIDLEY_HPP

#include "./iRidley.hpp"
#include "../wrappers/iSound.hpp"

class Ridley : public IRidley
{
public:
  Ridley(ISprite *rightSprite, ISprite *leftSprite, ISound *movementSound, ISound *deathSound);
  sf::Vector2f getPosition() const override;
  int getPoints() const override;
  int getDirection() const;
  void setPosition(const sf::Vector2f &position) override;
  void draw(IRenderWindow &window) const override;
  void changeDirection();
  void reset() override;
  void move() override;
  void spawn(int randomNumber = rand() % 2000) override;
  void stopMovementSoundIfPlaying() override;
  void stopMovementSoundIfAtSideOfWindow() override;
  void die() override;
  sf::FloatRect getGlobalBounds() const override;
  bool intersects(const sf::FloatRect &rectangle) const override;

private:
  ISprite *leftSprite_;
  int points_;
  int direction_;
  ISound *movementSound_;
  ISound *deathSound_;
};

#endif
