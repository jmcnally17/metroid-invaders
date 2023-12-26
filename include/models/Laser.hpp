#ifndef LASER_HPP
#define LASER_HPP

#include "./MovingGameObject.hpp"

class Laser : public MovingGameObject
{
public:
  Laser(float x, float y, ISprite *sprite, int direction);
  int getDirection() const;
  void move();
  
protected:
  int direction_;
};

#endif
