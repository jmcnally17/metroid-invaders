#include "../../../include/game.hpp"
#include "../../mockInterfaces/mockCollision.hpp"
#include "../../mockModels/mockGunship.hpp"
#include "../../mockModels/mockLaser.hpp"
#include "../../mockModels/mockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(evaluateGunshipMetroidLaserCollision, callsLoseLifeOnGunship)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> metroidLaser;
  MockLaser *pMetroidLaser = &metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = pMetroidLaser;
  }
  NiceMock<MockLaser> gunshipLaser;
  NiceMock<MockText> livesText;

  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(gunship, loseLife())
      .Times(1);
  evaluateGunshipMetroidLaserCollision(collision, gunship, metroidLasers, gunshipLaser, livesText);
}

TEST(evaluateGunshipMetroidLaserCollision, callsResetPositionOnGunship)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> metroidLaser;
  MockLaser *pMetroidLaser = &metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = pMetroidLaser;
  }
  NiceMock<MockLaser> gunshipLaser;
  NiceMock<MockText> livesText;

  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(gunship, resetPosition())
      .Times(1);
  evaluateGunshipMetroidLaserCollision(collision, gunship, metroidLasers, gunshipLaser, livesText);
}

TEST(evaluateGunshipMetroidLaserCollision, callsResetOnMetroidLasers)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockGunship> gunship;
  MockLaser metroidLaser;
  MockLaser *pMetroidLaser = &metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = pMetroidLaser;
  }
  NiceMock<MockLaser> gunshipLaser;
  NiceMock<MockText> livesText;

  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(metroidLaser, reset())
      .Times(3);
  evaluateGunshipMetroidLaserCollision(collision, gunship, metroidLasers, gunshipLaser, livesText);
}

TEST(evaluateGunshipMetroidLaserCollision, callsResetOnGunshipLaser)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> metroidLaser;
  MockLaser *pMetroidLaser = &metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = pMetroidLaser;
  }
  MockLaser gunshipLaser;
  NiceMock<MockText> livesText;

  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(gunshipLaser, reset())
      .Times(1);
  evaluateGunshipMetroidLaserCollision(collision, gunship, metroidLasers, gunshipLaser, livesText);
}

TEST(evaluateGunshipMetroidLaserCollision, updatesTheLivesText)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> metroidLaser;
  MockLaser *pMetroidLaser = &metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = pMetroidLaser;
  }
  NiceMock<MockLaser> gunshipLaser;
  MockText livesText;

  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));
  ON_CALL(gunship, getLives())
      .WillByDefault(Return(1));

  EXPECT_CALL(livesText, setString("Lives: 1"))
      .Times(1);
  evaluateGunshipMetroidLaserCollision(collision, gunship, metroidLasers, gunshipLaser, livesText);
}

TEST(evaluateGunshipMetroidLaserCollision, doesNotModifyAnythingIfThereAreNoCollisions)
{
  NiceMock<MockCollision> collision;
  MockGunship gunship;
  MockLaser metroidLaser;
  MockLaser *pMetroidLaser = &metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = pMetroidLaser;
  }
  MockLaser gunshipLaser;
  MockText livesText;

  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(false));
  ON_CALL(gunship, getLives())
      .WillByDefault(Return(1));

  EXPECT_CALL(gunship, loseLife())
      .Times(0);
  EXPECT_CALL(gunship, resetPosition())
      .Times(0);
  EXPECT_CALL(metroidLaser, reset())
      .Times(0);
  EXPECT_CALL(gunshipLaser, reset())
      .Times(0);
  EXPECT_CALL(livesText, setString)
      .Times(0);
  evaluateGunshipMetroidLaserCollision(collision, gunship, metroidLasers, gunshipLaser, livesText);
}
