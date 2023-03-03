#include "../../../include/game.hpp"
#include "../../mockModels/mockLaserCannon.hpp"

TEST(fireCannonLaser, callsFireOnLaserCannon)
{
  MockLaserCannon cannon;

  EXPECT_CALL(cannon, fire())
      .Times(1);
  fireCannonLaser(cannon);
}
