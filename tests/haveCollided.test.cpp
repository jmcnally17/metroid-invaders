#include "../include/spaceInvaders.hpp"
#include "./mockModels/mockLaser.hpp"
#include "./mockModels/mockInvader.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(hasInvaderBeenHit, returnsTrueForALaserCollidingWithTopOfInvader)
{
  NiceMock<MockLaser> laser;
  ON_CALL(laser, getWidth())
      .WillByDefault(Return(6));
  ON_CALL(laser, getHeight())
      .WillByDefault(Return(24));
  ON_CALL(laser, getPosition())
      .WillByDefault(Return(sf::Vector2f(400, 720)));

  NiceMock<MockInvader> invader;
  ON_CALL(invader, getWidth())
      .WillByDefault(Return(48));
  ON_CALL(invader, getHeight())
      .WillByDefault(Return(48));
  ON_CALL(invader, getPosition())
      .WillByDefault(Return(sf::Vector2f(390, 743)));

  EXPECT_TRUE(haveCollided(laser, invader));
}
