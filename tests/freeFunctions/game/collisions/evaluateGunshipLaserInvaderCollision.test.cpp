#include <vector>
#include "../../../../include/game.hpp"
#include "../../../mockInterfaces/mockCollision.hpp"
#include "../../../mockModels/mockLaser.hpp"
#include "../../../mockModels/mockMetroid.hpp"
#include "../../../mockModels/mockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(evaluateGunshipLaserMetroidCollision, killsMetroidThatIsAliveAndGunshipLaserIsCollidingWith)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockLaser> gunshipLaser;
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(10);
    for (int j = 0; j < 10; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  std::unordered_map<std::string, int> variables = {
    {"score", 0},
    {"highScore", 120},
  };
  NiceMock<MockText> scoreText;
  MockText highScoreText;

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

TEST(evaluateGunshipLaserMetroidCollision, addsTheMetroidPointsToTheScore)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockLaser> gunshipLaser;
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(10);
    for (int j = 0; j < 10; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  std::unordered_map<std::string, int> variables = {
    {"score", 0},
    {"highScore", 120},
  };
  MockText scoreText;
  MockText highScoreText;

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

TEST(evaluateGunshipLaserMetroidCollision, updatesTheHighScoreTextIfScoreSurpassesHighScore)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockLaser> gunshipLaser;
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(10);
    for (int j = 0; j < 10; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  std::unordered_map<std::string, int> variables = {
    {"score", 120},
    {"highScore", 120},
  };
  NiceMock<MockText> scoreText;
  MockText highScoreText;

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

TEST(evaluateGunshipLaserMetroidCollision, doesNotUpdateTheHighScoreTextIfScoreDoesNotSurpassHighScore)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockLaser> gunshipLaser;
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(10);
    for (int j = 0; j < 10; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  std::unordered_map<std::string, int> variables = {
    {"score", 0},
    {"highScore", 120},
  };
  NiceMock<MockText> scoreText;
  MockText highScoreText;

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

TEST(evaluateGunshipLaserMetroidCollision, doesNotKillMetroidsThatAreAliveAndGunshipLaserIsNotCollidingWith)
{
  NiceMock<MockCollision> collision;
  MockLaser gunshipLaser;
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(10);
    for (int j = 0; j < 10; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  std::unordered_map<std::string, int> variables = {
    {"score", 0},
    {"highScore", 120},
  };
  NiceMock<MockText> scoreText;
  MockText highScoreText;

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

TEST(evaluateGunshipLaserMetroidCollision, doesNotKillMetroidsThatAreDeadAndGunshipLaserIsCollidingWith)
{
  NiceMock<MockCollision> collision;
  MockLaser gunshipLaser;
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(10);
    for (int j = 0; j < 10; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  std::unordered_map<std::string, int> variables = {
    {"score", 0},
    {"highScore", 120},
  };
  NiceMock<MockText> scoreText;
  MockText highScoreText;

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

TEST(evaluateGunshipLaserMetroidCollision, doesNotKillMetroidsThatAreDeadAndGunshipLaserIsNotCollidingWith)
{
  NiceMock<MockCollision> collision;
  MockLaser gunshipLaser;
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(10);
    for (int j = 0; j < 10; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  std::unordered_map<std::string, int> variables = {
    {"score", 0},
    {"highScore", 120},
  };
  NiceMock<MockText> scoreText;
  MockText highScoreText;

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
