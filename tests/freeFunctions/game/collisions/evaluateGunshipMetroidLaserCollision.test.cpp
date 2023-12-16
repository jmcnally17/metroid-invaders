#include "../../../../include/game.hpp"
#include "../../../mockInterfaces/mockCollision.hpp"
#include "../../../mockModels/mockGunship.hpp"
#include "../../../mockModels/mockLaser.hpp"
#include "../../../mockModels/mockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class EvaluateGunshipMetroidLaserCollisionTest : public testing::Test
{
protected:
  NiceMock<MockCollision> collision;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> metroidLaser;
  MockLaser *pMetroidLaser {&metroidLaser};
  std::array<ILaser*, 3> metroidLasers {pMetroidLaser, pMetroidLaser, pMetroidLaser};
  NiceMock<MockLaser> gunshipLaser;
  NiceMock<MockText> livesText;
};

TEST_F(EvaluateGunshipMetroidLaserCollisionTest, callsLoseLifeOnGunship)
{
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(gunship, loseLife())
      .Times(1);
  evaluateGunshipMetroidLaserCollision(collision, gunship, metroidLasers, gunshipLaser, livesText);
}

TEST_F(EvaluateGunshipMetroidLaserCollisionTest, callsResetPositionOnGunship)
{
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(gunship, resetPosition())
      .Times(1);
  evaluateGunshipMetroidLaserCollision(collision, gunship, metroidLasers, gunshipLaser, livesText);
}

TEST_F(EvaluateGunshipMetroidLaserCollisionTest, callsResetOnMetroidLasers)
{
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(metroidLaser, reset())
      .Times(3);
  evaluateGunshipMetroidLaserCollision(collision, gunship, metroidLasers, gunshipLaser, livesText);
}

TEST_F(EvaluateGunshipMetroidLaserCollisionTest, callsResetOnGunshipLaser)
{
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(gunshipLaser, reset())
      .Times(1);
  evaluateGunshipMetroidLaserCollision(collision, gunship, metroidLasers, gunshipLaser, livesText);
}

TEST_F(EvaluateGunshipMetroidLaserCollisionTest, updatesTheLivesText)
{
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));
  ON_CALL(gunship, getLives())
      .WillByDefault(Return(1));

  EXPECT_CALL(livesText, setString("Lives: 1"))
      .Times(1);
  evaluateGunshipMetroidLaserCollision(collision, gunship, metroidLasers, gunshipLaser, livesText);
}

TEST_F(EvaluateGunshipMetroidLaserCollisionTest, doesNotModifyAnythingIfThereAreNoCollisions)
{
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
