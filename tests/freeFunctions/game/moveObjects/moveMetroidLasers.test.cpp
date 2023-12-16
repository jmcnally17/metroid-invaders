#include "../../../../include/game.hpp"
#include "../../../mockModels/mockLaser.hpp"

TEST(moveMetroidLasers, callsMoveOnMetroidLasers)
{
  MockLaser metroidLaser;
  MockLaser *pMetroidLaser {&metroidLaser};
  std::array<ILaser*, 3> metroidLasers {pMetroidLaser, pMetroidLaser, pMetroidLaser};

  EXPECT_CALL(metroidLaser, move())
      .Times(3);
  moveMetroidLasers(metroidLasers);
}
