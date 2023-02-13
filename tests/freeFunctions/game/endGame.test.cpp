#include <gtest/gtest.h>
#include "../../../include/game.hpp"

TEST(endGame, changesIsPlayingToFalse)
{
  bool isPlaying = true;
  bool gameOver = false;

  endGame(isPlaying, gameOver);
  EXPECT_EQ(isPlaying, false);
}

TEST(endGame, changesGameOverToTrue)
{
  bool isPlaying = true;
  bool gameOver = false;

  endGame(isPlaying, gameOver);
  EXPECT_EQ(gameOver, true);
}
