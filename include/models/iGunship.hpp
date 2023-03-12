#ifndef I_GUNSHIP_HPP
#define I_GUNSHIP_HPP

#include "./objectInterface.hpp"

class IGunship : public ObjectInterface
{
public:
  IGunship();
  IGunship(float x, float y, ISprite *sprite);
  virtual void move(float x) = 0;
  virtual void fire() = 0;
  virtual void loseLife() = 0;
  virtual void resetPosition() = 0;
  virtual int getLives() const = 0;
};

#endif
