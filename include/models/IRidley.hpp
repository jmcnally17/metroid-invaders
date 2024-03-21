#ifndef I_RIDLEY_HPP
#define I_RIDLEY_HPP

#include "./IGameObject.hpp"

class IRidley : public IGameObject
{
public:
  virtual int getPoints() const = 0;
  virtual void spawn(int randomNumber = rand() % 2000) = 0;
  virtual void move() = 0;
  virtual void reset() = 0;
  virtual void stopMovementSoundIfPlaying() = 0;
  virtual void stopMovementSoundIfAtSideOfWindow() = 0;
  virtual void die() = 0;
};

#endif
