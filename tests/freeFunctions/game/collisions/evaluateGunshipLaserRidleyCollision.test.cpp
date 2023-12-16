#include "../../../../include/game.hpp"
#include "../../../mockInterfaces/mockCollision.hpp"
#include "../../../mockModels/mockLaser.hpp"
#include "../../../mockModels/mockRidley.hpp"
#include "../../../mockModels/mockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class EvaluateGunshipLaserRidleyCollisionTest : public testing::Test
{
protected:
  NiceMock<MockCollision> collision;
  NiceMock<MockLaser> gunshipLaser;
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

  EXPECT_CALL(gunshipLaser, reset())
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
  EXPECT_CALL(gunshipLaser, reset())
      .Times(0);
  evaluateGunshipLaserRidleyCollision(collision, gunshipLaser, ridley, variables, scoreText, highScoreText);
  EXPECT_EQ(variables["score"], 430);
}
