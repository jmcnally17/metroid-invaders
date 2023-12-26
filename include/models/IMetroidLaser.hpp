#ifndef I_METROID_LASER_HPP
#define I_METROID_LASER_HPP

#include "./IGameObject.hpp"

class IMetroidLaser : public IGameObject
{
public:
  virtual void resetPosition() = 0;
  virtual void move() = 0;
};

#endif
