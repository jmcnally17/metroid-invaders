#include "../../../include/game.hpp"
#include "../../mockModels/mockLaserCannon.hpp"
#include "../../mockModels/mockLaser.hpp"

using ::testing::NiceMock;

TEST(decreaseCannonLives, callsLoseLifeOnCannon)
{
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;

  EXPECT_CALL(cannon, loseLife())
      .Times(1);
  decreaseCannonLives(cannon, cannonLaser);
}

TEST(decreaseCannonLives, callsResetPositionOnCannon)
{
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;

  EXPECT_CALL(cannon, resetPosition())
      .Times(1);
  decreaseCannonLives(cannon, cannonLaser);
}

TEST(decreaseCannonLives, callsResetOnCannonLaser)
{
  NiceMock<MockLaserCannon> cannon;
  MockLaser cannonLaser;

  EXPECT_CALL(cannonLaser, reset())
      .Times(1);
  decreaseCannonLives(cannon, cannonLaser);
}
