#include "../../../include/gameOver.hpp"
#include "../../mockModels/mockText.hpp"
#include "../../mockModels/mockSound.hpp"
#include "../../mockModels/mockClock.hpp"

using ::testing::NiceMock;

TEST(resetInformationObjects, updatesScoreText)
{
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
  resetInformationObjects(scoreText, livesText, creditsTheme, battleTheme, clock);
}

TEST(resetInformationObjects, updatesLivesText)
{
  NiceMock<MockText> scoreText;
  MockText livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  EXPECT_CALL(livesText, setString("Lives: 3"))
      .Times(1);
  resetInformationObjects(scoreText, livesText, creditsTheme, battleTheme, clock);
}

TEST(resetInformationObjects, stopsTheCreditsTheme)
{
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  MockSound creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  EXPECT_CALL(creditsTheme, stop())
      .Times(1);
  resetInformationObjects(scoreText, livesText, creditsTheme, battleTheme, clock);
}

TEST(resetInformationObjects, playsTheBattleTheme)
{
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  MockSound battleTheme;
  NiceMock<MockClock> clock;

  EXPECT_CALL(battleTheme, play())
      .Times(1);
  resetInformationObjects(scoreText, livesText, creditsTheme, battleTheme, clock);
}

TEST(resetInformationObjects, restartsClock)
{
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  MockClock clock;

  EXPECT_CALL(clock, restart())
      .Times(1);
  resetInformationObjects(scoreText, livesText, creditsTheme, battleTheme, clock);
}
