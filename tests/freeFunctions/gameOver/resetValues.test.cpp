#include "../../../include/gameOver.hpp"
#include "../../mockModels/mockText.hpp"
#include "../../mockModels/mockSound.hpp"
#include "../../mockModels/mockClock.hpp"

using ::testing::NiceMock;

TEST(resetValues, setsIsPlayingToTrue)
{
  bool isPlaying = false;
  bool gameOver = true;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  resetValues(isPlaying, gameOver, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
  EXPECT_TRUE(isPlaying);
}

TEST(resetValues, setsGameOverToFalse)
{
  bool isPlaying = false;
  bool gameOver = true;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  resetValues(isPlaying, gameOver, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
  EXPECT_FALSE(gameOver);
}

TEST(resetValues, resetsClockInterval)
{
  bool isPlaying = false;
  bool gameOver = true;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  resetValues(isPlaying, gameOver, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
  EXPECT_EQ(interval, 665);
}

TEST(resetValues, resetsClockStepCounter)
{
  bool isPlaying = false;
  bool gameOver = true;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  resetValues(isPlaying, gameOver, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
  EXPECT_EQ(step, 1);
}

TEST(resetValues, resetsSoundCounter)
{
  bool isPlaying = false;
  bool gameOver = true;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  resetValues(isPlaying, gameOver, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
  EXPECT_EQ(soundCounter, 0);
}

TEST(resetValues, resetsLevel)
{
  bool isPlaying = false;
  bool gameOver = true;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  resetValues(isPlaying, gameOver, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
  EXPECT_EQ(level, 1);
}

TEST(resetValues, resetsScore)
{
  bool isPlaying = false;
  bool gameOver = true;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  resetValues(isPlaying, gameOver, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
  EXPECT_EQ(score, 0);
}

TEST(resetValues, updatesScoreText)
{
  bool isPlaying = false;
  bool gameOver = true;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  MockText scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  EXPECT_CALL(scoreText, setString("Score: 0"))
      .Times(1);
  EXPECT_CALL(scoreText, setPosition(sf::Vector2f(20, 0)))
      .Times(1);
  EXPECT_CALL(scoreText, setOrigin(0, 0))
      .Times(1);
  resetValues(isPlaying, gameOver, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
}

TEST(resetValues, updatesLivesText)
{
  bool isPlaying = false;
  bool gameOver = true;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  MockText livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  EXPECT_CALL(livesText, setString("Lives: 3"))
      .Times(1);
  resetValues(isPlaying, gameOver, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
}

TEST(resetValues, stopsTheCreditsTheme)
{
  bool isPlaying = false;
  bool gameOver = true;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  MockSound creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  EXPECT_CALL(creditsTheme, stop())
      .Times(1);
  resetValues(isPlaying, gameOver, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
}

TEST(resetValues, playsTheBattleTheme)
{
  bool isPlaying = false;
  bool gameOver = true;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  MockSound battleTheme;
  NiceMock<MockClock> clock;

  EXPECT_CALL(battleTheme, play())
      .Times(1);
  resetValues(isPlaying, gameOver, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
}

TEST(resetValues, restartsClock)
{
  bool isPlaying = false;
  bool gameOver = true;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  MockClock clock;

  EXPECT_CALL(clock, restart())
      .Times(1);
  resetValues(isPlaying, gameOver, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
}
