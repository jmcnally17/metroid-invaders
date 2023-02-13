#include <gtest/gtest.h>
#include "../../../include/gameOver.hpp"

TEST(playAgain, setsGameOverToFalse)
{
  bool gameOver = true;

  playAgain(gameOver);
  EXPECT_EQ(gameOver, false);
}
