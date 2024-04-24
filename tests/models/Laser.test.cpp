#include "../../include/Constants.hpp"
#include "../../include/models/Laser.hpp"
#include "../mockModels/MockSprite.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class LaserTest : public testing::Test
{
protected:
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite {&sprite};
  Laser laser {Laser(12.5 * Constants::lengthScale, 18.75 * Constants::lengthScale, pSprite, -1)};
};

TEST_F(LaserTest, setsSpeedUponInstantiation)
{
  EXPECT_FLOAT_EQ(laser.getSpeed(), 0.4 * Constants::lengthScale);
}

TEST_F(LaserTest, setsDirectionUponInstantiation)
{
  EXPECT_EQ(laser.getDirection(), -1);
}

TEST_F(LaserTest, moveCallsMoveOnSpriteVerticallyAccordingToSpeedAndDirection)
{
  EXPECT_CALL(sprite, move(sf::Vector2f(0, -0.4 * Constants::lengthScale)))
    .Times(1);
  laser.move();
}
