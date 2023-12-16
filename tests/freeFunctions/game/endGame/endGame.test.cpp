#include "../../../../include/game.hpp"
#include "../../../mockModels/mockRidley.hpp"
#include "../../../mockModels/mockSound.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class EndGameTest : public testing::Test
{
protected:
  bool isPlaying {true};
  bool gameOver {false};
  NiceMock<MockRidley> ridley;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockSound> creditsTheme;
};

TEST_F(EndGameTest, changesIsPlayingToFalse)
{
  endGame(isPlaying, gameOver, ridley, battleTheme, creditsTheme);
  EXPECT_FALSE(isPlaying);
}

TEST_F(EndGameTest, changesGameOverToTrue)
{
  endGame(isPlaying, gameOver, ridley, battleTheme, creditsTheme);
  EXPECT_TRUE(gameOver);
}

TEST_F(EndGameTest, stopsRidleyMovementSoundIfPlaying)
{
  EXPECT_CALL(ridley, stopMovementSoundIfPlaying())
      .Times(1);
  endGame(isPlaying, gameOver, ridley, battleTheme, creditsTheme);
}

TEST_F(EndGameTest, stopsTheBattleTheme)
{
  EXPECT_CALL(battleTheme, stop())
      .Times(1);
  endGame(isPlaying, gameOver, ridley, battleTheme, creditsTheme);
}

TEST_F(EndGameTest, playsTheCreditsTheme)
{
  EXPECT_CALL(creditsTheme, play())
      .Times(1);
  endGame(isPlaying, gameOver, ridley, battleTheme, creditsTheme);
}
