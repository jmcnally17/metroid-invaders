#include "../../../include/title.hpp"
#include "../../mockModels/mockSound.hpp"

using ::testing::NiceMock;

TEST(play, setsIsPlayingToTrue)
{
  bool isPlaying = false;
  NiceMock<MockSound> titleTheme;
  NiceMock<MockSound> battleTheme;

  play(isPlaying, titleTheme, battleTheme);
  EXPECT_TRUE(isPlaying);
}

TEST(play, stopsTheTitleTheme)
{
  bool isPlaying = false;
  MockSound titleTheme;
  NiceMock<MockSound> battleTheme;

  EXPECT_CALL(titleTheme, stop())
      .Times(1);
  play(isPlaying, titleTheme, battleTheme);
}

TEST(play, playsTheBattleTheme)
{
  bool isPlaying = false;
  NiceMock<MockSound> titleTheme;
  MockSound battleTheme;

  EXPECT_CALL(battleTheme, play())
      .Times(1);
  play(isPlaying, titleTheme, battleTheme);
}
