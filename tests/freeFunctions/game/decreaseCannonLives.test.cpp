#include "../../../include/game.hpp"
#include "../../mockModels/mockLaserCannon.hpp"
#include "../../mockModels/mockLaser.hpp"

using ::testing::NiceMock;

TEST(decreaseCannonLives, callsLoseLifeOnCannon)
{
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  std::vector<ILaser *> invaderLasers;

  EXPECT_CALL(cannon, loseLife())
      .Times(1);
  decreaseCannonLives(cannon, cannonLaser, invaderLasers);
}

TEST(decreaseCannonLives, callsResetPositionOnCannon)
{
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  std::vector<ILaser *> invaderLasers;

  EXPECT_CALL(cannon, resetPosition())
      .Times(1);
  decreaseCannonLives(cannon, cannonLaser, invaderLasers);
}

TEST(decreaseCannonLives, callsResetOnCannonLaser)
{
  NiceMock<MockLaserCannon> cannon;
  MockLaser cannonLaser;
  std::vector<ILaser *> invaderLasers;

  EXPECT_CALL(cannonLaser, reset())
      .Times(1);
  decreaseCannonLives(cannon, cannonLaser, invaderLasers);
}

TEST(decreaseCannonLives, callsResetOnInvaderLasers)
{
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  MockLaser invaderLaser;
  MockLaser *pInvaderLaser = &invaderLaser;
  std::vector<ILaser *> invaderLasers(3);
  for (int i = 0; i < 3; i++)
  {
    invaderLasers[i] = pInvaderLaser;
  }

  EXPECT_CALL(invaderLaser, reset())
      .Times(3);
  decreaseCannonLives(cannon, cannonLaser, invaderLasers);
}
