#ifndef INVADER_HPP
#define INVADER_HPP

#include "./MovingGameObject.hpp"
#include "../wrappers/ISound.hpp"

class Invader : public MovingGameObject
{
public:
  Invader(float x, float y, ISprite *sprite, float speed, int points, int direction, ISound *deathSound);
  int getPoints() const;
  int getDirection() const;
  void changeDirection();
  void move();
  void die();
  
protected:
  int points_;
  int direction_;
  ISound *deathSound_;
};

#endif
