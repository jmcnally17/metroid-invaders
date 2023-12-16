#include "../../../../include/game.hpp"
#include "../../../mockInterfaces/mockCollision.hpp"
#include "../../../mockModels/mockLaser.hpp"
#include "../../../mockModels/mockMetroid.hpp"
#include "../../../mockModels/mockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class EvaluateGunshipLaserMetroidCollisionTest : public testing::Test
{
protected:
  NiceMock<MockCollision> collision;
  NiceMock<MockLaser> gunshipLaser;
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid {&metroid};
  std::array<std::array<IMetroid*, 11>, 5> metroids {{
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
  }};
  std::unordered_map<std::string, int> variables {
    {"score", 0},
    {"highScore", 120},
  };
  NiceMock<MockText> scoreText;
  MockText highScoreText;
};

TEST_F(EvaluateGunshipLaserMetroidCollisionTest, killsMetroidThatIsAliveAndGunshipLaserIsCollidingWith)
{
  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(true));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(metroid, die())
      .Times(1);
  EXPECT_CALL(gunshipLaser, reset())
      .Times(1);
  EXPECT_CALL(gunshipLaser, playMetroidDeath())
      .Times(1);
  evaluateGunshipLaserMetroidCollision(collision, gunshipLaser, metroids, variables, scoreText, highScoreText);
}

TEST_F(EvaluateGunshipLaserMetroidCollisionTest, addsTheMetroidPointsToTheScore)
{
  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(true));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));
  ON_CALL(metroid, getPoints())
      .WillByDefault(Return(30));

  EXPECT_CALL(scoreText, setString("Score: 30"))
      .Times(1);
  evaluateGunshipLaserMetroidCollision(collision, gunshipLaser, metroids, variables, scoreText, highScoreText);
  EXPECT_EQ(variables["score"], 30);
}

TEST_F(EvaluateGunshipLaserMetroidCollisionTest, updatesTheHighScoreTextIfScoreSurpassesHighScore)
{
  variables["score"] = {120};

  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(true));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));
  ON_CALL(metroid, getPoints())
      .WillByDefault(Return(30));

  EXPECT_CALL(highScoreText, setString("High Score: 150"))
      .Times(1);
  evaluateGunshipLaserMetroidCollision(collision, gunshipLaser, metroids, variables, scoreText, highScoreText);
}

TEST_F(EvaluateGunshipLaserMetroidCollisionTest, doesNotUpdateTheHighScoreTextIfScoreDoesNotSurpassHighScore)
{
  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(true));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));
  ON_CALL(metroid, getPoints())
      .WillByDefault(Return(30));

  EXPECT_CALL(highScoreText, setString)
      .Times(0);
  evaluateGunshipLaserMetroidCollision(collision, gunshipLaser, metroids, variables, scoreText, highScoreText);
}

TEST_F(EvaluateGunshipLaserMetroidCollisionTest, doesNotKillMetroidsThatAreAliveAndGunshipLaserIsNotCollidingWith)
{
  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(true));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(false));

  EXPECT_CALL(metroid, die())
      .Times(0);
  EXPECT_CALL(gunshipLaser, reset())
      .Times(0);
  EXPECT_CALL(gunshipLaser, playMetroidDeath())
      .Times(0);
  evaluateGunshipLaserMetroidCollision(collision, gunshipLaser, metroids, variables, scoreText, highScoreText);
}

TEST_F(EvaluateGunshipLaserMetroidCollisionTest, doesNotKillMetroidsThatAreDeadAndGunshipLaserIsCollidingWith)
{
  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(false));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(metroid, die())
      .Times(0);
  EXPECT_CALL(gunshipLaser, reset())
      .Times(0);
  EXPECT_CALL(gunshipLaser, playMetroidDeath())
      .Times(0);
  evaluateGunshipLaserMetroidCollision(collision, gunshipLaser, metroids, variables, scoreText, highScoreText);
}

TEST_F(EvaluateGunshipLaserMetroidCollisionTest, doesNotKillMetroidsThatAreDeadAndGunshipLaserIsNotCollidingWith)
{
  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(false));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(false));

  EXPECT_CALL(metroid, die())
      .Times(0);
  EXPECT_CALL(gunshipLaser, reset())
      .Times(0);
  EXPECT_CALL(gunshipLaser, playMetroidDeath())
      .Times(0);
  evaluateGunshipLaserMetroidCollision(collision, gunshipLaser, metroids, variables, scoreText, highScoreText);
}
