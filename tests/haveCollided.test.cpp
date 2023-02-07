#include "../include/spaceInvaders.hpp"
#include "./mockModels/mockObjectInterface.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(haveCollided, returnsTrueForObject1CollidingWithTopOfObject2)
{
  NiceMock<MockObjectInterface> object1;
  ON_CALL(object1, getWidth())
      .WillByDefault(Return(24));
  ON_CALL(object1, getHeight())
      .WillByDefault(Return(24));
  ON_CALL(object1, getPosition())
      .WillByDefault(Return(sf::Vector2f(400, 720)));

  NiceMock<MockObjectInterface> object2;
  ON_CALL(object2, getWidth())
      .WillByDefault(Return(48));
  ON_CALL(object2, getHeight())
      .WillByDefault(Return(48));
  ON_CALL(object2, getPosition())
      .WillByDefault(Return(sf::Vector2f(390, 743)));

  EXPECT_TRUE(haveCollided(object1, object2));
}

TEST(haveCollided, returnsFalseForObject1belowObject2)
{
  NiceMock<MockObjectInterface> object1;
  ON_CALL(object1, getWidth())
      .WillByDefault(Return(24));
  ON_CALL(object1, getHeight())
      .WillByDefault(Return(24));
  ON_CALL(object1, getPosition())
      .WillByDefault(Return(sf::Vector2f(400, 800)));

  NiceMock<MockObjectInterface> object2;
  ON_CALL(object2, getWidth())
      .WillByDefault(Return(48));
  ON_CALL(object2, getHeight())
      .WillByDefault(Return(48));
  ON_CALL(object2, getPosition())
      .WillByDefault(Return(sf::Vector2f(390, 720)));

  EXPECT_FALSE(haveCollided(object1, object2));
}

TEST(haveCollided, returnsFalseForObject1ToTheLeftOfObject2)
{
  NiceMock<MockObjectInterface> object1;
  ON_CALL(object1, getWidth())
      .WillByDefault(Return(24));
  ON_CALL(object1, getHeight())
      .WillByDefault(Return(24));
  ON_CALL(object1, getPosition())
      .WillByDefault(Return(sf::Vector2f(200, 730)));

  NiceMock<MockObjectInterface> object2;
  ON_CALL(object2, getWidth())
      .WillByDefault(Return(48));
  ON_CALL(object2, getHeight())
      .WillByDefault(Return(48));
  ON_CALL(object2, getPosition())
      .WillByDefault(Return(sf::Vector2f(400, 720)));

  EXPECT_FALSE(haveCollided(object1, object2));
}
