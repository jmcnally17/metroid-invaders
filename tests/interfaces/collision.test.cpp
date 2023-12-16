#include "../../include/interfaces/collisionInterface.hpp"
#include "../mockModels/mockObjectInterface.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class CollisionTest : public testing::Test
{
protected:
  Collision collision;
  
  NiceMock<MockObjectInterface> object1;
  NiceMock<MockObjectInterface> object2;
  sf::FloatRect box;
};

TEST_F(CollisionTest, haveCollidedReturnsTrueForObject1CollidingWithObject2)
{
  ON_CALL(object2, getGlobalBounds)
      .WillByDefault(Return(box));
  ON_CALL(object1, intersects)
      .WillByDefault(Return(true));

  EXPECT_TRUE(collision.haveCollided(object1, object2));
}

TEST_F(CollisionTest, haveCollidedReturnsFalseForObject1NotCollidingWithObject2)
{
  ON_CALL(object2, getGlobalBounds)
      .WillByDefault(Return(box));
  ON_CALL(object1, intersects)
      .WillByDefault(Return(false));

  EXPECT_FALSE(collision.haveCollided(object1, object2));
}
