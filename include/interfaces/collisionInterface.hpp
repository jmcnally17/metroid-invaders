#ifndef COLLISION_INTERFACE_HPP
#define COLLISION_INTERFACE_HPP

#include "../models/objectInterface.hpp"

class CollisionInterface
{
public:
  virtual bool haveCollided(const ObjectInterface &object1, const ObjectInterface &object2) const = 0;
};

class Collision : public CollisionInterface
{
public:
  bool haveCollided(const ObjectInterface &object1, const ObjectInterface &object2) const override;
};

#endif
