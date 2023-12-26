#include "../../include/models/Laser.hpp"
#include "../mockModels/MockSprite.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class LaserTest : public testing::Test
{
protected:
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite {&sprite};
  Laser laser {Laser(200, 300, pSprite, -1)};
};

TEST_F(LaserTest, setsSpeedUponInstantiation)
{
  EXPECT_FLOAT_EQ(laser.getSpeed(), 6.4);
}

TEST_F(LaserTest, setsDirectionUponInstantiation)
{
  EXPECT_EQ(laser.getDirection(), -1);
}

TEST_F(LaserTest, moveCallsMoveOnSpriteVerticallyAccordingToSpeedAndDirection)
{
  EXPECT_CALL(sprite, move(sf::Vector2f(0, -6.4)))
    .Times(1);
  laser.move();
}
