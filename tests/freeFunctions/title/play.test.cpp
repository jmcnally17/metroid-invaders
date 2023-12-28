#include "../../../include/Title.hpp"
#include "../../mockModels/MockSound.hpp"
#include "../../mockModels/MockClock.hpp"

using ::testing::NiceMock;

class PlayTest : public testing::Test
{
protected:
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

TEST_F(PlayTest, setsIsPlayingToTrue)
{
  play(isPlaying, themes, movementClock);
  EXPECT_TRUE(isPlaying);
}

TEST_F(PlayTest, stopsTheTitleTheme)
{
  EXPECT_CALL(titleTheme, stop())
      .Times(1);
  play(isPlaying, themes, movementClock);
}

TEST_F(PlayTest, playsTheBattleTheme)
{
  EXPECT_CALL(battleTheme, play())
      .Times(1);
  play(isPlaying, themes, movementClock);
}

TEST_F(PlayTest, restartsTheClock)
{
  EXPECT_CALL(movementClock, restart())
      .Times(1);
  play(isPlaying, themes, movementClock);
}
