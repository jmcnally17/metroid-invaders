#include "../include/spaceInvaders.hpp"
#include "./mockModels/mockLaserCannon.hpp"

TEST(fireLaser, callsFireOnLaserCannon)
{
  MockLaserCannon cannon;

  EXPECT_CALL(cannon, fire())
      .Times(1);
  fireLaser(cannon);
}
