#include "../../../include/title.hpp"
#include "../../mockModels/mockSound.hpp"
#include "../../mockModels/mockClock.hpp"

using ::testing::NiceMock;

class PlayTest : public testing::Test
{
protected:
  bool isPlaying {false};
  NiceMock<MockSound> titleTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> movementClock;
};

TEST_F(PlayTest, setsIsPlayingToTrue)
{
  play(isPlaying, titleTheme, battleTheme, movementClock);
  EXPECT_TRUE(isPlaying);
}

TEST_F(PlayTest, stopsTheTitleTheme)
{
  EXPECT_CALL(titleTheme, stop())
      .Times(1);
  play(isPlaying, titleTheme, battleTheme, movementClock);
}

TEST_F(PlayTest, playsTheBattleTheme)
{
  EXPECT_CALL(battleTheme, play())
      .Times(1);
  play(isPlaying, titleTheme, battleTheme, movementClock);
}

TEST_F(PlayTest, restartsTheClock)
{
  EXPECT_CALL(movementClock, restart())
      .Times(1);
  play(isPlaying, titleTheme, battleTheme, movementClock);
}
