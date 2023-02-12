#include <gtest/gtest.h>
#include "../../include/spaceInvaders.hpp"

TEST(endGame, changesGameOverToTrue)
{
  bool gameOver = false;

  endGame(gameOver);
  EXPECT_EQ(gameOver, true);
}
