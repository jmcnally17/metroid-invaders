#include <gtest/gtest.h>
#include "../../../include/gameOver.hpp"

TEST(resetValues, setsIsPlayingToTrue)
{
  bool isPlaying = false;
  bool gameOver = true;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;

  resetValues(isPlaying, gameOver, interval, step, soundCounter, level, score);
  EXPECT_TRUE(isPlaying);
}

TEST(resetValues, setsGameOverToFalse)
{
  bool isPlaying = false;
  bool gameOver = true;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;

  resetValues(isPlaying, gameOver, interval, step, soundCounter, level, score);
  EXPECT_FALSE(gameOver);
}

TEST(resetValues, resetsClockInterval)
{
  bool isPlaying = false;
  bool gameOver = true;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;

  resetValues(isPlaying, gameOver, interval, step, soundCounter, level, score);
  EXPECT_EQ(interval, 665);
}

TEST(resetValues, resetsClockStepCounter)
{
  bool isPlaying = false;
  bool gameOver = true;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;

  resetValues(isPlaying, gameOver, interval, step, soundCounter, level, score);
  EXPECT_EQ(step, 1);
}

TEST(resetValues, resetsSoundCounter)
{
  bool isPlaying = false;
  bool gameOver = true;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;

  resetValues(isPlaying, gameOver, interval, step, soundCounter, level, score);
  EXPECT_EQ(soundCounter, 0);
}

TEST(resetValues, resetsLevel)
{
  bool isPlaying = false;
  bool gameOver = true;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;

  resetValues(isPlaying, gameOver, interval, step, soundCounter, level, score);
  EXPECT_EQ(level, 1);
}

TEST(resetValues, resetsScore)
{
  bool isPlaying = false;
  bool gameOver = true;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;

  resetValues(isPlaying, gameOver, interval, step, soundCounter, level, score);
  EXPECT_EQ(score, 0);
}
