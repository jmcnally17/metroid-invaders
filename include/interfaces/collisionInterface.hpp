#ifndef COLLISION_INTERFACE_HPP
#define COLLISION_INTERFACE_HPP

#include "../models/IGameObject.hpp"

class CollisionInterface
{
public:
  virtual bool haveCollided(const IGameObject &gameObject1, const IGameObject &gameObject2) const = 0;
};

class Collision : public CollisionInterface
{
public:
  bool haveCollided(const IGameObject &gameObject1, const IGameObject &gameObject2) const override;
};

#endif
