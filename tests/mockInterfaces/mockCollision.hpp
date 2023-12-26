#ifndef MOCK_COLLISION_HPP
#define MOCK_COLLISION_HPP

#include <gmock/gmock.h>
#include "../../include/interfaces/collisionInterface.hpp"

class MockCollision : public CollisionInterface
{
public:
  MOCK_METHOD(bool, haveCollided, (const IGameObject &gameObject1, const IGameObject &gameObject2), (const));
};

#endif
