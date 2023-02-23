#include "../../../include/game.hpp"
#include "../../mockModels/mockLaser.hpp"

TEST(moveInvaderLasers, callsMoveOnInvaderLasers)
{
  MockLaser laser;
  MockLaser *pLaser = &laser;
  std::vector<ILaser *> invaderLasers(3);
  for (int i = 0; i < 3; i++)
  {
    invaderLasers[i] = pLaser;
  }

  EXPECT_CALL(laser, move())
      .Times(3);
  moveInvaderLasers(invaderLasers);
}
