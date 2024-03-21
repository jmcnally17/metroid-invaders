#ifndef I_GUNSHIP_LASER_HPP
#define I_GUNSHIP_LASER_HPP

#include "./IGameObject.hpp"

class IGunshipLaser : public IGameObject
{
public:
  virtual void resetPosition() = 0;
  virtual void move() = 0;
};

#endif
