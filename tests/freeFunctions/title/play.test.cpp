#include "../../../include/title.hpp"
#include "../../mockModels/mockSound.hpp"

using ::testing::NiceMock;

TEST(play, setsIsPlayingToTrue)
{
  bool isPlaying = false;
  NiceMock<MockSound> titleTheme;

  play(isPlaying, titleTheme);
  EXPECT_TRUE(isPlaying);
}

TEST(play, stopsTheTitleTheme)
{
  bool isPlaying = false;
  MockSound titleTheme;

  EXPECT_CALL(titleTheme, stop())
      .Times(1);
  play(isPlaying, titleTheme);
}
