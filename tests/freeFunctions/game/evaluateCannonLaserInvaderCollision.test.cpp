#include <vector>
#include "../../../include/game.hpp"
#include "../../mockInterfaces/mockCollision.hpp"
#include "../../mockModels/mockLaser.hpp"
#include "../../mockModels/mockMetroid.hpp"
#include "../../mockModels/mockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(evaluateCannonLaserMetroidCollision, killsMetroidThatIsAliveAndCannonLaserIsCollidingWith)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockLaser> cannonLaser;
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
  int score = 0;
  NiceMock<MockText> scoreText;

  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(true));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(metroid, die())
      .Times(1);
  EXPECT_CALL(cannonLaser, reset())
      .Times(1);
  EXPECT_CALL(cannonLaser, playMetroidDeath())
      .Times(1);
  evaluateCannonLaserMetroidCollision(collision, cannonLaser, metroids, score, scoreText);
}

TEST(evaluateCannonLaserMetroidCollision, addsTheMetroidPointsToTheScore)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockLaser> cannonLaser;
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
  int score = 0;
  MockText scoreText;

  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(true));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));
  ON_CALL(metroid, getPoints())
      .WillByDefault(Return(30));

  EXPECT_CALL(scoreText, setString("Score: 30"))
      .Times(1);
  evaluateCannonLaserMetroidCollision(collision, cannonLaser, metroids, score, scoreText);
  EXPECT_EQ(score, 30);
}

TEST(evaluateCannonLaserMetroidCollision, doesNotKillMetroidsThatAreAliveAndCannonLaserIsNotCollidingWith)
{
  NiceMock<MockCollision> collision;
  MockLaser cannonLaser;
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
  int score = 0;
  NiceMock<MockText> scoreText;

  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(true));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(false));

  EXPECT_CALL(metroid, die())
      .Times(0);
  EXPECT_CALL(cannonLaser, reset())
      .Times(0);
  EXPECT_CALL(cannonLaser, playMetroidDeath())
      .Times(0);
  evaluateCannonLaserMetroidCollision(collision, cannonLaser, metroids, score, scoreText);
}

TEST(evaluateCannonLaserMetroidCollision, doesNotKillMetroidsThatAreDeadAndCannonLaserIsCollidingWith)
{
  NiceMock<MockCollision> collision;
  MockLaser cannonLaser;
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
  int score = 0;
  NiceMock<MockText> scoreText;

  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(false));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(metroid, die())
      .Times(0);
  EXPECT_CALL(cannonLaser, reset())
      .Times(0);
  EXPECT_CALL(cannonLaser, playMetroidDeath())
      .Times(0);
  evaluateCannonLaserMetroidCollision(collision, cannonLaser, metroids, score, scoreText);
}

TEST(evaluateCannonLaserMetroidCollision, doesNotKillMetroidsThatAreDeadAndCannonLaserIsNotCollidingWith)
{
  NiceMock<MockCollision> collision;
  MockLaser cannonLaser;
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
  int score = 0;
  NiceMock<MockText> scoreText;

  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(false));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(false));

  EXPECT_CALL(metroid, die())
      .Times(0);
  EXPECT_CALL(cannonLaser, reset())
      .Times(0);
  EXPECT_CALL(cannonLaser, playMetroidDeath())
      .Times(0);
  evaluateCannonLaserMetroidCollision(collision, cannonLaser, metroids, score, scoreText);
}
