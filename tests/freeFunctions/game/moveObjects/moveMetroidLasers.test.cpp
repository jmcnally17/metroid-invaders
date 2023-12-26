#include "../../../../include/Game.hpp"
#include "../../../mockModels/MockMetroidLaser.hpp"

TEST(moveMetroidLasers, callsMoveOnMetroidLasers)
{
  MockMetroidLaser metroidLaser;
  MockMetroidLaser *pMetroidLaser {&metroidLaser};
  std::array<IMetroidLaser*, 3> metroidLasers {pMetroidLaser, pMetroidLaser, pMetroidLaser};

  EXPECT_CALL(metroidLaser, move())
      .Times(3);
  moveMetroidLasers(metroidLasers);
}
