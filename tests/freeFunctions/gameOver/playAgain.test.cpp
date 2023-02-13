#include <vector>
#include "../../../include/gameOver.hpp"
#include "../../mockModels/mockLaserCannon.hpp"
#include "../../mockModels/mockLaser.hpp"
#include "../../mockModels/mockInvader.hpp"
#include "../../mockModels/mockText.hpp"
#include "../../mockModels/mockClock.hpp"

using ::testing::NiceMock;

TEST(playAgain, setsIsPlayingToTrue)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  std::vector<std::vector<IInvader *>> invaders;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockClock> clock;

  playAgain(isPlaying, gameOver, cannon, laser, invaders, interval, step, soundCounter, level, score, scoreText, clock);
  EXPECT_EQ(isPlaying, true);
}

TEST(playAgain, setsGameOverToFalse)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  std::vector<std::vector<IInvader *>> invaders;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockClock> clock;

  playAgain(isPlaying, gameOver, cannon, laser, invaders, interval, step, soundCounter, level, score, scoreText, clock);
  EXPECT_EQ(gameOver, false);
}

TEST(playAgain, resetsTheLaserCannon)
{
  bool isPlaying = false;
  bool gameOver = true;
  MockLaserCannon cannon;
  NiceMock<MockLaser> laser;
  std::vector<std::vector<IInvader *>> invaders;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockClock> clock;

  EXPECT_CALL(cannon, reset())
      .Times(1);
  playAgain(isPlaying, gameOver, cannon, laser, invaders, interval, step, soundCounter, level, score, scoreText, clock);
}

TEST(playAgain, resetsTheLaser)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  MockLaser laser;
  std::vector<std::vector<IInvader *>> invaders;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockClock> clock;

  EXPECT_CALL(laser, reset())
      .Times(1);
  playAgain(isPlaying, gameOver, cannon, laser, invaders, interval, step, soundCounter, level, score, scoreText, clock);
}

TEST(playAgain, resetsTheInvaders)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  MockInvader invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(6);
    for (int j = 0; j < 6; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockClock> clock;

  EXPECT_CALL(invader, reset())
      .Times(12);
  playAgain(isPlaying, gameOver, cannon, laser, invaders, interval, step, soundCounter, level, score, scoreText, clock);
}

TEST(playAgain, resetsClockInterval)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  std::vector<std::vector<IInvader *>> invaders;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockClock> clock;

  playAgain(isPlaying, gameOver, cannon, laser, invaders, interval, step, soundCounter, level, score, scoreText, clock);
  EXPECT_EQ(interval, 665);
}

TEST(playAgain, resetsClockStepCounter)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  std::vector<std::vector<IInvader *>> invaders;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockClock> clock;

  playAgain(isPlaying, gameOver, cannon, laser, invaders, interval, step, soundCounter, level, score, scoreText, clock);
  EXPECT_EQ(step, 1);
}

TEST(playAgain, resetsSoundCounter)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  std::vector<std::vector<IInvader *>> invaders;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockClock> clock;

  playAgain(isPlaying, gameOver, cannon, laser, invaders, interval, step, soundCounter, level, score, scoreText, clock);
  EXPECT_EQ(soundCounter, 0);
}

TEST(playAgain, resetsLevel)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  std::vector<std::vector<IInvader *>> invaders;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockClock> clock;

  playAgain(isPlaying, gameOver, cannon, laser, invaders, interval, step, soundCounter, level, score, scoreText, clock);
  EXPECT_EQ(level, 1);
}

TEST(playAgain, resetsScore)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  std::vector<std::vector<IInvader *>> invaders;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockClock> clock;

  playAgain(isPlaying, gameOver, cannon, laser, invaders, interval, step, soundCounter, level, score, scoreText, clock);
  EXPECT_EQ(score, 0);
}

TEST(playAgain, updatesScoreText)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  std::vector<std::vector<IInvader *>> invaders;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  MockText scoreText;
  NiceMock<MockClock> clock;

  EXPECT_CALL(scoreText, setString("Score: 0"))
      .Times(1);
  EXPECT_CALL(scoreText, setPosition(sf::Vector2f(20, 0)))
      .Times(1);
  EXPECT_CALL(scoreText, setOrigin(0, 0))
      .Times(1);
  playAgain(isPlaying, gameOver, cannon, laser, invaders, interval, step, soundCounter, level, score, scoreText, clock);
}

TEST(playAgain, restartsClock)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  std::vector<std::vector<IInvader *>> invaders;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  MockClock clock;

  EXPECT_CALL(clock, restart())
      .Times(1);
  playAgain(isPlaying, gameOver, cannon, laser, invaders, interval, step, soundCounter, level, score, scoreText, clock);
}
