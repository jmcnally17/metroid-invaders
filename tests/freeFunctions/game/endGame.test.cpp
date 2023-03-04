#include "../../../include/game.hpp"
#include "../../mockModels/mockRidley.hpp"
#include "../../mockModels/mockText.hpp"
#include "../../mockModels/mockSound.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(endGame, changesIsPlayingToFalse)
{
  bool isPlaying = true;
  bool gameOver = false;
  NiceMock<MockRidley> ridley;
  int score = 1200;
  NiceMock<MockText> scoreText;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockSound> creditsTheme;

  endGame(isPlaying, gameOver, ridley, score, scoreText, battleTheme, creditsTheme);
  EXPECT_FALSE(isPlaying);
}

TEST(endGame, changesGameOverToTrue)
{
  bool isPlaying = true;
  bool gameOver = false;
  NiceMock<MockRidley> ridley;
  int score = 1200;
  NiceMock<MockText> scoreText;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockSound> creditsTheme;

  endGame(isPlaying, gameOver, ridley, score, scoreText, battleTheme, creditsTheme);
  EXPECT_TRUE(gameOver);
}

TEST(endGame, stopsRidleyMovementSoundIfPlaying)
{
  bool isPlaying = true;
  bool gameOver = false;
  MockRidley ridley;
  int score = 1200;
  NiceMock<MockText> scoreText;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockSound> creditsTheme;

  EXPECT_CALL(ridley, stopMovementSoundIfPlaying())
      .Times(1);
  endGame(isPlaying, gameOver, ridley, score, scoreText, battleTheme, creditsTheme);
}

TEST(endGame, updatesScoreText)
{
  bool isPlaying = true;
  bool gameOver = false;
  NiceMock<MockRidley> ridley;
  int score = 1200;
  NiceMock<MockText> scoreText;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockSound> creditsTheme;

  ON_CALL(scoreText, getLocalBounds())
      .WillByDefault(Return(sf::FloatRect(20, 20, 400, 50)));

  EXPECT_CALL(scoreText, setString("You scored 1200 points"))
      .Times(1);
  EXPECT_CALL(scoreText, setPosition(sf::Vector2f(768, 600)))
      .Times(1);
  EXPECT_CALL(scoreText, setOrigin(200, 0))
      .Times(1);
  endGame(isPlaying, gameOver, ridley, score, scoreText, battleTheme, creditsTheme);
}

TEST(endGame, stopsTheBattleTheme)
{
  bool isPlaying = true;
  bool gameOver = false;
  NiceMock<MockRidley> ridley;
  int score = 1200;
  NiceMock<MockText> scoreText;
  MockSound battleTheme;
  NiceMock<MockSound> creditsTheme;

  EXPECT_CALL(battleTheme, stop())
      .Times(1);
  endGame(isPlaying, gameOver, ridley, score, scoreText, battleTheme, creditsTheme);
}

TEST(endGame, playsTheCreditsTheme)
{
  bool isPlaying = true;
  bool gameOver = false;
  NiceMock<MockRidley> ridley;
  int score = 1200;
  NiceMock<MockText> scoreText;
  NiceMock<MockSound> battleTheme;
  MockSound creditsTheme;

  EXPECT_CALL(creditsTheme, play())
      .Times(1);
  endGame(isPlaying, gameOver, ridley, score, scoreText, battleTheme, creditsTheme);
}
