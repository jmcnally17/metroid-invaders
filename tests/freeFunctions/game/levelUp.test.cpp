#include <gtest/gtest.h>
#include "../../../include/game.hpp"

TEST(levelUp, adds1ToTheLevelVariable)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;

  levelUp(level, interval, step, soundCounter);
  EXPECT_EQ(level, 6);
}

TEST(levelUp, resetsTheInterval)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;

  levelUp(level, interval, step, soundCounter);
  EXPECT_EQ(interval, 665);
}

TEST(levelUp, resetsTheStepCounter)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;

  levelUp(level, interval, step, soundCounter);
  EXPECT_EQ(step, 1);
}

TEST(levelUp, resetsTheSoundCounter)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;

  levelUp(level, interval, step, soundCounter);
  EXPECT_EQ(soundCounter, 0);
}
