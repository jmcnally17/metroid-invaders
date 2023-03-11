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
  NiceMock<MockClock> movementClock;

  EXPECT_CALL(scoreText, setString("Score: 0"))
      .Times(1);
  EXPECT_CALL(scoreText, setPosition(sf::Vector2f(20, 0)))
      .Times(1);
  EXPECT_CALL(scoreText, setOrigin(0, 0))
      .Times(1);
  resetInformationObjects(scoreText, livesText, creditsTheme, battleTheme, movementClock);
}

TEST(resetInformationObjects, updatesLivesText)
{
  NiceMock<MockText> scoreText;
  MockText livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> movementClock;

  EXPECT_CALL(livesText, setString("Lives: 3"))
      .Times(1);
  resetInformationObjects(scoreText, livesText, creditsTheme, battleTheme, movementClock);
}

TEST(resetInformationObjects, stopsTheCreditsTheme)
{
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  MockSound creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> movementClock;

  EXPECT_CALL(creditsTheme, stop())
      .Times(1);
  resetInformationObjects(scoreText, livesText, creditsTheme, battleTheme, movementClock);
}

TEST(resetInformationObjects, playsTheBattleTheme)
{
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  MockSound battleTheme;
  NiceMock<MockClock> movementClock;

  EXPECT_CALL(battleTheme, play())
      .Times(1);
  resetInformationObjects(scoreText, livesText, creditsTheme, battleTheme, movementClock);
}

TEST(resetInformationObjects, restartsClock)
{
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  MockClock movementClock;

  EXPECT_CALL(movementClock, restart())
      .Times(1);
  resetInformationObjects(scoreText, livesText, creditsTheme, battleTheme, movementClock);
}
