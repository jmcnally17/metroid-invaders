#include <gtest/gtest.h>
#include "../../../include/game.hpp"

TEST(levelUp, adds1ToTheLevelVariable)
{
  int level = 5;

  levelUp(level);
  EXPECT_EQ(level, 6);
}
