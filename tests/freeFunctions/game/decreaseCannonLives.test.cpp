#include "../../../include/game.hpp"
#include "../../mockModels/mockLaserCannon.hpp"

TEST(decreaseCannonLives, callsLoseLifeOnCannon)
{
  MockLaserCannon cannon;

  EXPECT_CALL(cannon, loseLife())
      .Times(1);
  decreaseCannonLives(cannon);
}
