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
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockText> livesText;

  EXPECT_CALL(cannon, loseLife())
      .Times(1);
  decreaseCannonLives(cannon, cannonLaser, metroidLasers, livesText);
}

TEST(decreaseCannonLives, callsResetPositionOnCannon)
{
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockText> livesText;

  EXPECT_CALL(cannon, resetPosition())
      .Times(1);
  decreaseCannonLives(cannon, cannonLaser, metroidLasers, livesText);
}

TEST(decreaseCannonLives, callsResetOnCannonLaser)
{
  NiceMock<MockLaserCannon> cannon;
  MockLaser cannonLaser;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockText> livesText;

  EXPECT_CALL(cannonLaser, reset())
      .Times(1);
  decreaseCannonLives(cannon, cannonLaser, metroidLasers, livesText);
}

TEST(decreaseCannonLives, callsResetOnMetroidLasers)
{
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  MockLaser metroidLaser;
  MockLaser *pMetroidLaser = &metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = pMetroidLaser;
  }
  NiceMock<MockText> livesText;

  EXPECT_CALL(metroidLaser, reset())
      .Times(3);
  decreaseCannonLives(cannon, cannonLaser, metroidLasers, livesText);
}

TEST(decreaseCannonLives, updatesTheLivesText)
{
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  std::vector<ILaser *> metroidLasers;
  MockText livesText;

  ON_CALL(cannon, getLives())
      .WillByDefault(Return(1));

  EXPECT_CALL(livesText, setString("Lives: 1"))
      .Times(1);
  decreaseCannonLives(cannon, cannonLaser, metroidLasers, livesText);
}
