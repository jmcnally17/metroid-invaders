#include "../../../../include/game.hpp"
#include "../../../mockModels/mockLaser.hpp"

TEST(moveMetroidLasers, callsMoveOnMetroidLasers)
{
  MockLaser metroidLaser;
  MockLaser *pMetroidLaser = &metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = pMetroidLaser;
  }

  EXPECT_CALL(metroidLaser, move())
      .Times(3);
  moveMetroidLasers(metroidLasers);
}
