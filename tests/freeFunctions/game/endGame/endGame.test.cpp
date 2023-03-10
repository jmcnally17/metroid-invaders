#include "../../../../include/game.hpp"
#include "../../../mockModels/mockRidley.hpp"
#include "../../../mockModels/mockSound.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(endGame, changesIsPlayingToFalse)
{
  bool isPlaying = true;
  bool gameOver = false;
  NiceMock<MockRidley> ridley;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockSound> creditsTheme;

  endGame(isPlaying, gameOver, ridley, battleTheme, creditsTheme);
  EXPECT_FALSE(isPlaying);
}

TEST(endGame, changesGameOverToTrue)
{
  bool isPlaying = true;
  bool gameOver = false;
  NiceMock<MockRidley> ridley;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockSound> creditsTheme;

  endGame(isPlaying, gameOver, ridley, battleTheme, creditsTheme);
  EXPECT_TRUE(gameOver);
}

TEST(endGame, stopsRidleyMovementSoundIfPlaying)
{
  bool isPlaying = true;
  bool gameOver = false;
  MockRidley ridley;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockSound> creditsTheme;

  EXPECT_CALL(ridley, stopMovementSoundIfPlaying())
      .Times(1);
  endGame(isPlaying, gameOver, ridley, battleTheme, creditsTheme);
}

TEST(endGame, stopsTheBattleTheme)
{
  bool isPlaying = true;
  bool gameOver = false;
  NiceMock<MockRidley> ridley;
  MockSound battleTheme;
  NiceMock<MockSound> creditsTheme;

  EXPECT_CALL(battleTheme, stop())
      .Times(1);
  endGame(isPlaying, gameOver, ridley, battleTheme, creditsTheme);
}

TEST(endGame, playsTheCreditsTheme)
{
  bool isPlaying = true;
  bool gameOver = false;
  NiceMock<MockRidley> ridley;
  NiceMock<MockSound> battleTheme;
  MockSound creditsTheme;

  EXPECT_CALL(creditsTheme, play())
      .Times(1);
  endGame(isPlaying, gameOver, ridley, battleTheme, creditsTheme);
}
