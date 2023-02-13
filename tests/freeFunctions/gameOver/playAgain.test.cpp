#include <gtest/gtest.h>
#include "../../../include/gameOver.hpp"

TEST(playAgain, setsIsPlayingToTrue)
{
  bool isPlaying = false;
  bool gameOver = true;

  playAgain(isPlaying, gameOver);
  EXPECT_EQ(isPlaying, true);
}

TEST(playAgain, setsGameOverToFalse)
{
  bool isPlaying = false;
  bool gameOver = true;

  playAgain(isPlaying, gameOver);
  EXPECT_EQ(gameOver, false);
}
