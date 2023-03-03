#include <vector>
#include "../../../include/gameOver.hpp"
#include "../../mockModels/mockLaserCannon.hpp"
#include "../../mockModels/mockLaser.hpp"
#include "../../mockModels/mockMetroid.hpp"
#include "../../mockModels/mockRidley.hpp"
#include "../../mockModels/mockText.hpp"
#include "../../mockModels/mockClock.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(playAgain, setsIsPlayingToTrue)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockClock> clock;

  playAgain(isPlaying, gameOver, cannon, cannonLaser, metroids, metroidLasers, ridley, interval, step, soundCounter, level, score, scoreText, livesText, clock);
  EXPECT_TRUE(isPlaying);
}

TEST(playAgain, setsGameOverToFalse)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockClock> clock;

  playAgain(isPlaying, gameOver, cannon, cannonLaser, metroids, metroidLasers, ridley, interval, step, soundCounter, level, score, scoreText, livesText, clock);
  EXPECT_FALSE(gameOver);
}

TEST(playAgain, resetsTheLaserCannon)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockClock> clock;

  EXPECT_CALL(cannon, reset())
      .Times(1);
  playAgain(isPlaying, gameOver, cannon, cannonLaser, metroids, metroidLasers, ridley, interval, step, soundCounter, level, score, scoreText, livesText, clock);
}

TEST(playAgain, resetsTheCannonLaser)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  MockLaser cannonLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockClock> clock;

  EXPECT_CALL(cannonLaser, reset())
      .Times(1);
  playAgain(isPlaying, gameOver, cannon, cannonLaser, metroids, metroidLasers, ridley, interval, step, soundCounter, level, score, scoreText, livesText, clock);
}

TEST(playAgain, resetsTheMetroids)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  MockMetroid metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(6);
    for (int j = 0; j < 6; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockClock> clock;

  EXPECT_CALL(metroid, reset())
      .Times(12);
  playAgain(isPlaying, gameOver, cannon, cannonLaser, metroids, metroidLasers, ridley, interval, step, soundCounter, level, score, scoreText, livesText, clock);
}

TEST(playAgain, resetsMetroidLasers)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  MockLaser metroidLaser;
  MockLaser *pMetroidLaser = &metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = pMetroidLaser;
  }
  NiceMock<MockRidley> ridley;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockClock> clock;

  EXPECT_CALL(metroidLaser, reset())
      .Times(3);
  playAgain(isPlaying, gameOver, cannon, cannonLaser, metroids, metroidLasers, ridley, interval, step, soundCounter, level, score, scoreText, livesText, clock);
}

TEST(playAgain, resetsRidley)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  MockRidley ridley;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockClock> clock;

  EXPECT_CALL(ridley, reset())
      .Times(1);
  playAgain(isPlaying, gameOver, cannon, cannonLaser, metroids, metroidLasers, ridley, interval, step, soundCounter, level, score, scoreText, livesText, clock);
}

TEST(playAgain, resetsClockInterval)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockClock> clock;

  playAgain(isPlaying, gameOver, cannon, cannonLaser, metroids, metroidLasers, ridley, interval, step, soundCounter, level, score, scoreText, livesText, clock);
  EXPECT_EQ(interval, 665);
}

TEST(playAgain, resetsClockStepCounter)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockClock> clock;

  playAgain(isPlaying, gameOver, cannon, cannonLaser, metroids, metroidLasers, ridley, interval, step, soundCounter, level, score, scoreText, livesText, clock);
  EXPECT_EQ(step, 1);
}

TEST(playAgain, resetsSoundCounter)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockClock> clock;

  playAgain(isPlaying, gameOver, cannon, cannonLaser, metroids, metroidLasers, ridley, interval, step, soundCounter, level, score, scoreText, livesText, clock);
  EXPECT_EQ(soundCounter, 0);
}

TEST(playAgain, resetsLevel)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockClock> clock;

  playAgain(isPlaying, gameOver, cannon, cannonLaser, metroids, metroidLasers, ridley, interval, step, soundCounter, level, score, scoreText, livesText, clock);
  EXPECT_EQ(level, 1);
}

TEST(playAgain, resetsScore)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockClock> clock;

  playAgain(isPlaying, gameOver, cannon, cannonLaser, metroids, metroidLasers, ridley, interval, step, soundCounter, level, score, scoreText, livesText, clock);
  EXPECT_EQ(score, 0);
}

TEST(playAgain, updatesScoreText)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  MockText scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockClock> clock;

  EXPECT_CALL(scoreText, setString("Score: 0"))
      .Times(1);
  EXPECT_CALL(scoreText, setPosition(sf::Vector2f(20, 0)))
      .Times(1);
  EXPECT_CALL(scoreText, setOrigin(0, 0))
      .Times(1);
  playAgain(isPlaying, gameOver, cannon, cannonLaser, metroids, metroidLasers, ridley, interval, step, soundCounter, level, score, scoreText, livesText, clock);
}

TEST(playAgain, updatesLivesText)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  MockText livesText;
  NiceMock<MockClock> clock;

  ON_CALL(cannon, getLives())
      .WillByDefault(Return(3));

  EXPECT_CALL(livesText, setString("Lives: 3"))
      .Times(1);
  playAgain(isPlaying, gameOver, cannon, cannonLaser, metroids, metroidLasers, ridley, interval, step, soundCounter, level, score, scoreText, livesText, clock);
}

TEST(playAgain, restartsClock)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> cannonLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  MockClock clock;

  EXPECT_CALL(clock, restart())
      .Times(1);
  playAgain(isPlaying, gameOver, cannon, cannonLaser, metroids, metroidLasers, ridley, interval, step, soundCounter, level, score, scoreText, livesText, clock);
}
