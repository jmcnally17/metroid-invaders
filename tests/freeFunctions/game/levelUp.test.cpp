#include <gtest/gtest.h>
#include "../../../include/game.hpp"

TEST(levelUp, adds1ToTheLevelVariable)
{
  int level = 5;
  int interval = 105;

  levelUp(level, interval);
  EXPECT_EQ(level, 6);
}

TEST(levelUp, resetsTheInterval)
{
  int level = 5;
  int interval = 105;

  levelUp(level, interval);
  EXPECT_EQ(interval, 665);
}
