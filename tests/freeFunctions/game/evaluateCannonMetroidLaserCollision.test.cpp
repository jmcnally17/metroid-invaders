#include "../../../include/game.hpp"
#include "../../mockInterfaces/mockCollision.hpp"
#include "../../mockModels/mockLaserCannon.hpp"
#include "../../mockModels/mockLaser.hpp"
#include "../../mockModels/mockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(evaluateCannonMetroidLaserCollision, callsLoseLifeOnCannon)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> metroidLaser;
  MockLaser *pMetroidLaser = &metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = pMetroidLaser;
  }
  NiceMock<MockLaser> cannonLaser;
  NiceMock<MockText> livesText;

  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(cannon, loseLife())
      .Times(1);
  evaluateCannonMetroidLaserCollision(collision, cannon, metroidLasers, cannonLaser, livesText);
}

TEST(evaluateCannonMetroidLaserCollision, callsResetPositionOnCannon)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> metroidLaser;
  MockLaser *pMetroidLaser = &metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = pMetroidLaser;
  }
  NiceMock<MockLaser> cannonLaser;
  NiceMock<MockText> livesText;

  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(cannon, resetPosition())
      .Times(1);
  evaluateCannonMetroidLaserCollision(collision, cannon, metroidLasers, cannonLaser, livesText);
}

TEST(evaluateCannonMetroidLaserCollision, callsResetOnMetroidLasers)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockLaserCannon> cannon;
  MockLaser metroidLaser;
  MockLaser *pMetroidLaser = &metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = pMetroidLaser;
  }
  NiceMock<MockLaser> cannonLaser;
  NiceMock<MockText> livesText;

  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(metroidLaser, reset())
      .Times(3);
  evaluateCannonMetroidLaserCollision(collision, cannon, metroidLasers, cannonLaser, livesText);
}

TEST(evaluateCannonMetroidLaserCollision, callsResetOnCannonLaser)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> metroidLaser;
  MockLaser *pMetroidLaser = &metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = pMetroidLaser;
  }
  MockLaser cannonLaser;
  NiceMock<MockText> livesText;

  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(cannonLaser, reset())
      .Times(1);
  evaluateCannonMetroidLaserCollision(collision, cannon, metroidLasers, cannonLaser, livesText);
}

TEST(evaluateCannonMetroidLaserCollision, updatesTheLivesText)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> metroidLaser;
  MockLaser *pMetroidLaser = &metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = pMetroidLaser;
  }
  NiceMock<MockLaser> cannonLaser;
  MockText livesText;

  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));
  ON_CALL(cannon, getLives())
      .WillByDefault(Return(1));

  EXPECT_CALL(livesText, setString("Lives: 1"))
      .Times(1);
  evaluateCannonMetroidLaserCollision(collision, cannon, metroidLasers, cannonLaser, livesText);
}

TEST(evaluateCannonMetroidLaserCollision, doesNotModifyAnythingIfThereAreNoCollisions)
{
  NiceMock<MockCollision> collision;
  MockLaserCannon cannon;
  MockLaser metroidLaser;
  MockLaser *pMetroidLaser = &metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = pMetroidLaser;
  }
  MockLaser cannonLaser;
  MockText livesText;

  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(false));
  ON_CALL(cannon, getLives())
      .WillByDefault(Return(1));

  EXPECT_CALL(cannon, loseLife())
      .Times(0);
  EXPECT_CALL(cannon, resetPosition())
      .Times(0);
  EXPECT_CALL(metroidLaser, reset())
      .Times(0);
  EXPECT_CALL(cannonLaser, reset())
      .Times(0);
  EXPECT_CALL(livesText, setString)
      .Times(0);
  evaluateCannonMetroidLaserCollision(collision, cannon, metroidLasers, cannonLaser, livesText);
}
