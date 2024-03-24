#include "../../include/helpers/Game.hpp"
#include "../mockModels/MockClock.hpp"
#include "../mockModels/MockSound.hpp"

using ::testing::NiceMock;

class GameTest : public ::testing::Test
{
protected:
  Game game;
  std::unordered_map<std::string, int> variables {};
  bool isPlaying {false};
  NiceMock<MockSound> titleTheme;
  MockSound *pTitleTheme {&titleTheme};
  NiceMock<MockSound> battleTheme;
  MockSound *pBattleTheme {&battleTheme};
  std::unordered_map<std::string, ISound*> themes {
    {"title", pTitleTheme},
    {"battle", pBattleTheme},
  };
  NiceMock<MockClock> movementClock;
};

TEST_F(GameTest, playSetsIsPlayingToTrue)
{
  game.play(isPlaying, themes, movementClock);
  EXPECT_TRUE(isPlaying);
}

TEST_F(GameTest, playStopsTheTitleTheme)
{
  EXPECT_CALL(titleTheme, stop())
      .Times(1);
  game.play(isPlaying, themes, movementClock);
}

TEST_F(GameTest, playPlaysTheBattleTheme)
{
  EXPECT_CALL(battleTheme, play())
      .Times(1);
  game.play(isPlaying, themes, movementClock);
}

TEST_F(GameTest, playRestartsTheClock)
{
  EXPECT_CALL(movementClock, restart())
      .Times(1);
  game.play(isPlaying, themes, movementClock);
}
