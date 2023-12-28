#include "../../../../include/Game.hpp"
#include "../../../mockModels/MockRidley.hpp"
#include "../../../mockModels/MockSound.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class EndGameTest : public testing::Test
{
protected:
  bool isPlaying {true};
  bool gameOver {false};
  NiceMock<MockRidley> ridley;
  NiceMock<MockSound> battleTheme;
  MockSound *pBattleTheme {&battleTheme};
  NiceMock<MockSound> creditsTheme;
  MockSound *pCreditsTheme {&creditsTheme};
  std::unordered_map<std::string, ISound*> themes {
    {"battle", pBattleTheme},
    {"credits", pCreditsTheme},
  };
};

TEST_F(EndGameTest, changesIsPlayingToFalse)
{
  endGame(isPlaying, gameOver, ridley, themes);
  EXPECT_FALSE(isPlaying);
}

TEST_F(EndGameTest, changesGameOverToTrue)
{
  endGame(isPlaying, gameOver, ridley, themes);
  EXPECT_TRUE(gameOver);
}

TEST_F(EndGameTest, stopsRidleyMovementSoundIfPlaying)
{
  EXPECT_CALL(ridley, stopMovementSoundIfPlaying())
      .Times(1);
  endGame(isPlaying, gameOver, ridley, themes);
}

TEST_F(EndGameTest, stopsTheBattleTheme)
{
  EXPECT_CALL(battleTheme, stop())
      .Times(1);
  endGame(isPlaying, gameOver, ridley, themes);
}

TEST_F(EndGameTest, playsTheCreditsTheme)
{
  EXPECT_CALL(creditsTheme, play())
      .Times(1);
  endGame(isPlaying, gameOver, ridley, themes);
}
