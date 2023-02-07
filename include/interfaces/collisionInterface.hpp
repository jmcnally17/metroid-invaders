#ifndef COLLISION_INTERFACE_HPP
#define COLLISION_INTERFACE_HPP

#include "../models/objectInterface.hpp"

class CollisionInterface
{
public:
  virtual bool haveCollided(ObjectInterface &object1, ObjectInterface &object2) const = 0;
};

class Collision : public CollisionInterface
{
public:
  bool haveCollided(ObjectInterface &object1, ObjectInterface &object2) const override;
};

#endif
