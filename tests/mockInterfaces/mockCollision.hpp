#ifndef MOCK_COLLISION_HPP
#define MOCK_COLLISION_HPP

#include <gmock/gmock.h>
#include "../../include/interfaces/collisionInterface.hpp"

class MockCollision : public CollisionInterface
{
public:
  MOCK_METHOD(bool, haveCollided, (const ObjectInterface &object1, const ObjectInterface &object2), (const));
};

#endif
