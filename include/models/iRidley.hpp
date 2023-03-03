#ifndef I_RIDLEY_HPP
#define I_RIDLEY_HPP

#include "./objectInterface.hpp"

class IRidley : public ObjectInterface
{
public:
  IRidley();
  IRidley(float width, float height, float x, float y, ISprite *sprite);
  virtual void move() = 0;
  virtual void spawn(int randomNumber = rand() % 10000) = 0;
  virtual void stopMovementSoundIfPlaying() = 0;
  virtual void stopMovementSoundIfAtSideOfWindow() = 0;
  ;
};

#endif
