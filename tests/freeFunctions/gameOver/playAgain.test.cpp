#include "../../../include/gameOver.hpp"
#include "../../mockModels/mockLaserCannon.hpp"

TEST(playAgain, setsIsPlayingToTrue)
{
  bool isPlaying = false;
  bool gameOver = true;
  MockLaserCannon cannon;

  playAgain(isPlaying, gameOver, cannon);
  EXPECT_EQ(isPlaying, true);
}

TEST(playAgain, setsGameOverToFalse)
{
  bool isPlaying = false;
  bool gameOver = true;
  MockLaserCannon cannon;

  playAgain(isPlaying, gameOver, cannon);
  EXPECT_EQ(gameOver, false);
}

TEST(playAgain, resetsTheLaserCannon)
{
  bool isPlaying = false;
  bool gameOver = true;
  MockLaserCannon cannon;

  EXPECT_CALL(cannon, reset())
      .Times(1);
  playAgain(isPlaying, gameOver, cannon);
}
