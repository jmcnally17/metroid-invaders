#include "../../include/interfaces/collisionInterface.hpp"
#include "../mockModels/mockObjectInterface.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(collision, haveCollidedReturnsTrueForObject1CollidingWithTopOfObject2)
{
    Collision collision;

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

    EXPECT_TRUE(collision.haveCollided(object1, object2));
}

TEST(collision, haveCollidedReturnsFalseForObject1belowObject2)
{
    Collision collision;

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

    EXPECT_FALSE(collision.haveCollided(object1, object2));
}

TEST(collision, haveCollidedReturnsFalseForObject1ToTheLeftOfObject2)
{
    Collision collision;

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

    EXPECT_FALSE(collision.haveCollided(object1, object2));
}

TEST(collision, haveCollidedReturnsFalseForObject1ToTheRightOfObject2)
{
    Collision collision;

    NiceMock<MockObjectInterface> object1;
    ON_CALL(object1, getWidth())
        .WillByDefault(Return(24));
    ON_CALL(object1, getHeight())
        .WillByDefault(Return(24));
    ON_CALL(object1, getPosition())
        .WillByDefault(Return(sf::Vector2f(450, 730)));

    NiceMock<MockObjectInterface> object2;
    ON_CALL(object2, getWidth())
        .WillByDefault(Return(48));
    ON_CALL(object2, getHeight())
        .WillByDefault(Return(48));
    ON_CALL(object2, getPosition())
        .WillByDefault(Return(sf::Vector2f(400, 720)));

    EXPECT_FALSE(collision.haveCollided(object1, object2));
}
