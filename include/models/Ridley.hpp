#ifndef RIDLEY_HPP
#define RIDLEY_HPP

#include "./Invader.hpp"
#include "./IRidley.hpp"
#include "../adaptors/ISound.hpp"

class Ridley : public Invader, public IRidley
{
public:
  Ridley(ISprite *rightSprite, ISound *deathSound, ISprite *leftSprite, ISound *movementSound);
  sf::Vector2f getPosition() const override;
  void setPosition(const sf::Vector2f &position) override;
  void draw(IRenderWindow &window) const override;
  sf::FloatRect getGlobalBounds() const override;
  bool intersects(const IGameObject &gameObject) const override;
  int getPoints() const override;
  void spawn(int randomNumber = rand() % (12500000 / Constants::FRAME_LENGTH)) override;
  void move() override;
  void reset() override;
  void stopMovementSoundIfPlaying() override;
  void stopMovementSoundIfAtSideOfWindow() override;
  void die() override;

private:
  ISprite *leftSprite_;
  ISound *movementSound_;
};

#endif
