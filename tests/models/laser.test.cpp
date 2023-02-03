#include <gtest/gtest.h>
#include "../../include/models/laser.hpp"
#include "../mockModels/mockSprite.hpp"

using ::testing::NiceMock;

TEST(Laser, hasAPositionUponInstantiation)
{
  NiceMock<MockSprite> sprite;
  Laser laser(sprite);

  EXPECT_EQ(laser.getPosition(), sf::Vector2f(120, -24));
}

TEST(Laser, setsSpritePositionUponInstantiation)
{
  MockSprite sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, -24)));
  Laser laser(sprite);
}

TEST(Laser, setPositionChangesPositionClassMember)
{
  NiceMock<MockSprite> sprite;
  Laser laser(sprite);

  laser.setPosition(sf::Vector2f(530, 890));
  EXPECT_EQ(laser.getPosition(), sf::Vector2f(530, 890));
}
