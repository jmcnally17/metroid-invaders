#include "../../../include/game.hpp"
#include "../../mockModels/mockLaser.hpp"

TEST(moveMetroidLasers, callsMoveOnMetroidLasers)
{
  MockLaser laser;
  MockLaser *pLaser = &laser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = pLaser;
  }

  EXPECT_CALL(laser, move())
      .Times(3);
  moveMetroidLasers(metroidLasers);
}
