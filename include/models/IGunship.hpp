#ifndef I_GUNSHIP_HPP
#define I_GUNSHIP_HPP

#include "./IGameObject.hpp"

class IGunship : public IGameObject
{
public:
  virtual void resetPosition() = 0;
  virtual int getLives() const = 0;
  virtual void move(int direction) = 0;
  virtual void fire() = 0;
  virtual void loseLife() = 0;
  virtual void reset() = 0;
};

#endif
