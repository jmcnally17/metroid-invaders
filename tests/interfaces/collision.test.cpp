#include "../../include/interfaces/collisionInterface.hpp"
#include "../mockModels/MockGameObject.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class CollisionTest : public testing::Test
{
protected:
  Collision collision;
  
  NiceMock<MockGameObject> gameObject1;
  NiceMock<MockGameObject> gameObject2;
};

TEST_F(CollisionTest, haveCollidedReturnsTrueForObject1CollidingWithObject2)
{
  ON_CALL(gameObject1, intersects)
      .WillByDefault(Return(true));

  EXPECT_TRUE(collision.haveCollided(gameObject1, gameObject2));
}

TEST_F(CollisionTest, haveCollidedReturnsFalseForObject1NotCollidingWithObject2)
{
  ON_CALL(gameObject1, intersects)
      .WillByDefault(Return(false));

  EXPECT_FALSE(collision.haveCollided(gameObject1, gameObject2));
}
