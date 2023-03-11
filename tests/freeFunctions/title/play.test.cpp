#include "../../../include/title.hpp"
#include "../../mockModels/mockSound.hpp"
#include "../../mockModels/mockClock.hpp"

using ::testing::NiceMock;

TEST(play, setsIsPlayingToTrue)
{
  bool isPlaying = false;
  NiceMock<MockSound> titleTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> movementClock;

  play(isPlaying, titleTheme, battleTheme, movementClock);
  EXPECT_TRUE(isPlaying);
}

TEST(play, stopsTheTitleTheme)
{
  bool isPlaying = false;
  MockSound titleTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> movementClock;

  EXPECT_CALL(titleTheme, stop())
      .Times(1);
  play(isPlaying, titleTheme, battleTheme, movementClock);
}

TEST(play, playsTheBattleTheme)
{
  bool isPlaying = false;
  NiceMock<MockSound> titleTheme;
  MockSound battleTheme;
  NiceMock<MockClock> movementClock;

  EXPECT_CALL(battleTheme, play())
      .Times(1);
  play(isPlaying, titleTheme, battleTheme, movementClock);
}

TEST(play, restartsTheClock)
{
  bool isPlaying = false;
  NiceMock<MockSound> titleTheme;
  NiceMock<MockSound> battleTheme;
  MockClock movementClock;

  EXPECT_CALL(movementClock, restart())
      .Times(1);
  play(isPlaying, titleTheme, battleTheme, movementClock);
}
