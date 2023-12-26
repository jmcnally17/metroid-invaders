#include "../../../../include/Game.hpp"
#include "../../../mockInterfaces/MockCollision.hpp"
#include "../../../mockModels/MockGunshipLaser.hpp"
#include "../../../mockModels/MockRidley.hpp"
#include "../../../mockModels/MockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class EvaluateGunshipLaserRidleyCollisionTest : public testing::Test
{
protected:
  NiceMock<MockCollision> collision;
  NiceMock<MockGunshipLaser> gunshipLaser;
  NiceMock<MockRidley> ridley;
  std::unordered_map<std::string, int> variables {
    {"score", 430},
    {"highScore", 1000},
  };
  NiceMock<MockText> scoreText;
  MockText highScoreText;
};

TEST_F(EvaluateGunshipLaserRidleyCollisionTest, killsRidleyIfCollidingWithGunshipLaser)
{
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(ridley, die())
      .Times(1);
  evaluateGunshipLaserRidleyCollision(collision, gunshipLaser, ridley, variables, scoreText, highScoreText);
}

TEST_F(EvaluateGunshipLaserRidleyCollisionTest, addsTheRidleyPointsToTheScore)
{
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));
  ON_CALL(ridley, getPoints())
      .WillByDefault(Return(150));

  EXPECT_CALL(scoreText, setString("Score: 580"))
      .Times(1);
  evaluateGunshipLaserRidleyCollision(collision, gunshipLaser, ridley, variables, scoreText, highScoreText);
  EXPECT_EQ(variables["score"], 580);
}

TEST_F(EvaluateGunshipLaserRidleyCollisionTest, updatesTheHighScoreTextIfScoreSurpassesHighScore)
{
  variables["highScore"] = {450};

  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));
  ON_CALL(ridley, getPoints())
      .WillByDefault(Return(150));

  EXPECT_CALL(highScoreText, setString("High Score: 580"))
      .Times(1);
  evaluateGunshipLaserRidleyCollision(collision, gunshipLaser, ridley, variables, scoreText, highScoreText);
}

TEST_F(EvaluateGunshipLaserRidleyCollisionTest, doesNotUpdatesTheHighScoreTextIfScoreDoesNotSurpassHighScore)
{
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));
  ON_CALL(ridley, getPoints())
      .WillByDefault(Return(150));

  EXPECT_CALL(highScoreText, setString)
      .Times(0);
  evaluateGunshipLaserRidleyCollision(collision, gunshipLaser, ridley, variables, scoreText, highScoreText);
}

TEST_F(EvaluateGunshipLaserRidleyCollisionTest, resetsTheGunshipLaser)
{
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(gunshipLaser, resetPosition())
      .Times(1);
  evaluateGunshipLaserRidleyCollision(collision, gunshipLaser, ridley, variables, scoreText, highScoreText);
}

TEST_F(EvaluateGunshipLaserRidleyCollisionTest, doesNotModifyAnythingIfRidleyAndLaserAreNotColliding)
{
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(false));
  ON_CALL(ridley, getPoints())
      .WillByDefault(Return(150));

  EXPECT_CALL(ridley, die())
      .Times(0);
  EXPECT_CALL(scoreText, setString)
      .Times(0);
  EXPECT_CALL(gunshipLaser, resetPosition)
      .Times(0);
  evaluateGunshipLaserRidleyCollision(collision, gunshipLaser, ridley, variables, scoreText, highScoreText);
  EXPECT_EQ(variables["score"], 430);
}
