#include "../../include/models/MovingGameObject.hpp"
#include "../mockModels/MockSprite.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class MovingGameObjectTest : public testing::Test
{
protected:
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite {&sprite};
  MovingGameObject movingGameObject {MovingGameObject(200, 300, pSprite, 4.5)};
};

TEST_F(MovingGameObjectTest, setsOriginalPositionUponInstantiation)
{
  EXPECT_EQ(movingGameObject.getOriginalPosition(), sf::Vector2f(200, 300));
}

TEST_F(MovingGameObjectTest, hasASpeedPropertyUponInstantiation)
{
  EXPECT_EQ(movingGameObject.getSpeed(), 4.5);
}

TEST_F(MovingGameObjectTest, resetPositionSetsSpritePositionBackToOriginalPosition)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 300)))
    .Times(1);
  movingGameObject.resetPosition();
}
