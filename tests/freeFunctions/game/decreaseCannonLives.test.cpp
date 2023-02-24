#include "../../../include/game.hpp"
#include "../../mockModels/mockLaserCannon.hpp"
#include "../../mockModels/mockLaser.hpp"
#include "../../mockModels/mockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(decreaseCannonLives, callsLoseLifeOnCannon)
{
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  std::vector<ILaser *> invaderLasers;
  NiceMock<MockText> livesText;

  EXPECT_CALL(cannon, loseLife())
      .Times(1);
  decreaseCannonLives(cannon, cannonLaser, invaderLasers, livesText);
}

TEST(decreaseCannonLives, callsResetPositionOnCannon)
{
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  std::vector<ILaser *> invaderLasers;
  NiceMock<MockText> livesText;

  EXPECT_CALL(cannon, resetPosition())
      .Times(1);
  decreaseCannonLives(cannon, cannonLaser, invaderLasers, livesText);
}

TEST(decreaseCannonLives, callsResetOnCannonLaser)
{
  NiceMock<MockLaserCannon> cannon;
  MockLaser cannonLaser;
  std::vector<ILaser *> invaderLasers;
  NiceMock<MockText> livesText;

  EXPECT_CALL(cannonLaser, reset())
      .Times(1);
  decreaseCannonLives(cannon, cannonLaser, invaderLasers, livesText);
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
  NiceMock<MockText> livesText;

  EXPECT_CALL(invaderLaser, reset())
      .Times(3);
  decreaseCannonLives(cannon, cannonLaser, invaderLasers, livesText);
}

TEST(decreaseCannonLives, updatesTheLivesText)
{
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  std::vector<ILaser *> invaderLasers;
  MockText livesText;

  ON_CALL(cannon, getLives())
      .WillByDefault(Return(1));

  EXPECT_CALL(livesText, setString("Lives: 1"))
      .Times(1);
  decreaseCannonLives(cannon, cannonLaser, invaderLasers, livesText);
}
