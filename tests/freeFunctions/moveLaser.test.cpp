#include "../../include/spaceInvaders.hpp"
#include "../mockModels/mockLaser.hpp"

TEST(moveLaser, callsMoveOnLaser)
{
  MockLaser laser;

  EXPECT_CALL(laser, move())
      .Times(1);
  moveLaser(laser);
}
