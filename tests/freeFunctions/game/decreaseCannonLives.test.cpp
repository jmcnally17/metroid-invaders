#include "../../../include/game.hpp"
#include "../../mockModels/mockLaserCannon.hpp"

using ::testing::NiceMock;

TEST(decreaseCannonLives, callsLoseLifeOnCannon)
{
  NiceMock<MockLaserCannon> cannon;

  EXPECT_CALL(cannon, loseLife())
      .Times(1);
  decreaseCannonLives(cannon);
}

TEST(decreaseCannonLives, callsResetPositionOnCannon)
{
  NiceMock<MockLaserCannon> cannon;

  EXPECT_CALL(cannon, resetPosition())
      .Times(1);
  decreaseCannonLives(cannon);
}
