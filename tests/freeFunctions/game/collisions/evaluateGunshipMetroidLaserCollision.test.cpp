#include "../../../../include/Game.hpp"
#include "../../../mockModels/MockGunship.hpp"
#include "../../../mockModels/MockMetroidLaser.hpp"
#include "../../../mockModels/MockGunshipLaser.hpp"
#include "../../../mockModels/mockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class EvaluateGunshipMetroidLaserCollisionTest : public testing::Test
{
protected:
  NiceMock<MockGunship> gunship;
  NiceMock<MockMetroidLaser> metroidLaser;
  MockMetroidLaser *pMetroidLaser {&metroidLaser};
  std::array<IMetroidLaser*, 3> metroidLasers {pMetroidLaser, pMetroidLaser, pMetroidLaser};
  NiceMock<MockGunshipLaser> gunshipLaser;
  NiceMock<MockText> livesText;
  MockText *pLivesText {&livesText};
  std::unordered_map<std::string, IText*> textObjects {
    {"lives", pLivesText},
  };
};

TEST_F(EvaluateGunshipMetroidLaserCollisionTest, callsLoseLifeOnGunship)
{
  ON_CALL(gunship, intersects)
      .WillByDefault(Return(true));

  EXPECT_CALL(gunship, loseLife())
      .Times(1);
  evaluateGunshipMetroidLaserCollision(gunship, metroidLasers, gunshipLaser, textObjects);
}

TEST_F(EvaluateGunshipMetroidLaserCollisionTest, callsResetPositionOnGunship)
{
  ON_CALL(gunship, intersects)
      .WillByDefault(Return(true));

  EXPECT_CALL(gunship, resetPosition())
      .Times(1);
  evaluateGunshipMetroidLaserCollision(gunship, metroidLasers, gunshipLaser, textObjects);
}

TEST_F(EvaluateGunshipMetroidLaserCollisionTest, callsResetOnMetroidLasers)
{
  ON_CALL(gunship, intersects)
      .WillByDefault(Return(true));

  EXPECT_CALL(metroidLaser, resetPosition())
      .Times(3);
  evaluateGunshipMetroidLaserCollision(gunship, metroidLasers, gunshipLaser, textObjects);
}

TEST_F(EvaluateGunshipMetroidLaserCollisionTest, callsResetOnGunshipLaser)
{
  ON_CALL(gunship, intersects)
      .WillByDefault(Return(true));

  EXPECT_CALL(gunshipLaser, resetPosition())
      .Times(1);
  evaluateGunshipMetroidLaserCollision(gunship, metroidLasers, gunshipLaser, textObjects);
}

TEST_F(EvaluateGunshipMetroidLaserCollisionTest, updatesTheLivesText)
{
  ON_CALL(gunship, intersects)
      .WillByDefault(Return(true));
  ON_CALL(gunship, getLives())
      .WillByDefault(Return(1));

  EXPECT_CALL(livesText, setString("Lives: 1"))
      .Times(1);
  evaluateGunshipMetroidLaserCollision(gunship, metroidLasers, gunshipLaser, textObjects);
}

TEST_F(EvaluateGunshipMetroidLaserCollisionTest, doesNotModifyAnythingIfThereAreNoCollisions)
{
  ON_CALL(gunship, intersects)
      .WillByDefault(Return(false));
  ON_CALL(gunship, getLives())
      .WillByDefault(Return(1));

  EXPECT_CALL(gunship, loseLife)
      .Times(0);
  EXPECT_CALL(gunship, resetPosition)
      .Times(0);
  EXPECT_CALL(metroidLaser, resetPosition)
      .Times(0);
  EXPECT_CALL(gunshipLaser, resetPosition)
      .Times(0);
  EXPECT_CALL(livesText, setString)
      .Times(0);
  evaluateGunshipMetroidLaserCollision(gunship, metroidLasers, gunshipLaser, textObjects);
}
