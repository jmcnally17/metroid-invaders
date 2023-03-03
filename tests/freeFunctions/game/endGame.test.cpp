#include <gtest/gtest.h>
#include "../../../include/game.hpp"
#include "../../mockModels/mockRidley.hpp"
#include "../../mockModels/mockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(endGame, changesIsPlayingToFalse)
{
  bool isPlaying = true;
  bool gameOver = false;
  NiceMock<MockRidley> ridley;
  int score = 1200;
  NiceMock<MockText> scoreText;

  endGame(isPlaying, gameOver, ridley, score, scoreText);
  EXPECT_FALSE(isPlaying);
}

TEST(endGame, changesGameOverToTrue)
{
  bool isPlaying = true;
  bool gameOver = false;
  NiceMock<MockRidley> ridley;
  int score = 1200;
  NiceMock<MockText> scoreText;

  endGame(isPlaying, gameOver, ridley, score, scoreText);
  EXPECT_TRUE(gameOver);
}

TEST(endGame, stopsRidleyMovementSoundIfPlaying)
{
  bool isPlaying = true;
  bool gameOver = false;
  MockRidley ridley;
  int score = 1200;
  NiceMock<MockText> scoreText;

  EXPECT_CALL(ridley, stopMovementSoundIfPlaying())
      .Times(1);
  endGame(isPlaying, gameOver, ridley, score, scoreText);
}

TEST(endGame, updatesScoreText)
{
  bool isPlaying = true;
  bool gameOver = false;
  NiceMock<MockRidley> ridley;
  int score = 1200;
  NiceMock<MockText> scoreText;

  ON_CALL(scoreText, getLocalBounds())
      .WillByDefault(Return(sf::FloatRect(20, 20, 400, 50)));

  EXPECT_CALL(scoreText, setString("You scored 1200 points"))
      .Times(1);
  EXPECT_CALL(scoreText, setPosition(sf::Vector2f(768, 600)))
      .Times(1);
  EXPECT_CALL(scoreText, setOrigin(200, 0))
      .Times(1);
  endGame(isPlaying, gameOver, ridley, score, scoreText);
}
