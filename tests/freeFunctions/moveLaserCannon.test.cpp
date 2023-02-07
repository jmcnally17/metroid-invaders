#include "../../include/spaceInvaders.hpp"
#include "../mockModels/mockLaserCannon.hpp"

TEST(moveLaserCannon, callsMoveOnTheLaserCannon)
{
  MockLaserCannon cannon;

  EXPECT_CALL(cannon, move(150))
      .Times(1);
  moveLaserCannon(cannon, 150);
}
