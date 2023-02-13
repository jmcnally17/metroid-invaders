#include <gtest/gtest.h>
#include "../../../include/game.hpp"
#include "../../mockModels/mockText.hpp"

using ::testing::NiceMock;

TEST(endGame, changesIsPlayingToFalse)
{
  bool isPlaying = true;
  bool gameOver = false;
  int score = 1200;
  NiceMock<MockText> scoreText;

  endGame(isPlaying, gameOver, score, scoreText);
  EXPECT_EQ(isPlaying, false);
}

TEST(endGame, changesGameOverToTrue)
{
  bool isPlaying = true;
  bool gameOver = false;
  int score = 1200;
  NiceMock<MockText> scoreText;

  endGame(isPlaying, gameOver, score, scoreText);
  EXPECT_EQ(gameOver, true);
}

TEST(endGame, updatesScoreText)
{
  bool isPlaying = true;
  bool gameOver = false;
  int score = 1200;
  MockText scoreText;

  EXPECT_CALL(scoreText, setString("You scored 1200 points"))
      .Times(1);
  endGame(isPlaying, gameOver, score, scoreText);
}
