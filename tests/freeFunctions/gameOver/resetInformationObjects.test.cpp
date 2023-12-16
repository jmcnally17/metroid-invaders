#include "../../../include/gameOver.hpp"
#include "../../mockModels/mockText.hpp"
#include "../../mockModels/mockSound.hpp"
#include "../../mockModels/mockClock.hpp"

using ::testing::NiceMock;

class ResetInformationObjectsTest : public testing::Test
{
protected:
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> movementClock;
};

TEST_F(ResetInformationObjectsTest, updatesScoreText)
{
  EXPECT_CALL(scoreText, setString("Score: 0"))
      .Times(1);
  EXPECT_CALL(scoreText, setPosition(sf::Vector2f(20, 0)))
      .Times(1);
  EXPECT_CALL(scoreText, setOrigin(0, 0))
      .Times(1);
  resetInformationObjects(scoreText, livesText, creditsTheme, battleTheme, movementClock);
}

TEST_F(ResetInformationObjectsTest, updatesLivesText)
{
  EXPECT_CALL(livesText, setString("Lives: 3"))
      .Times(1);
  resetInformationObjects(scoreText, livesText, creditsTheme, battleTheme, movementClock);
}

TEST_F(ResetInformationObjectsTest, stopsTheCreditsTheme)
{
  EXPECT_CALL(creditsTheme, stop())
      .Times(1);
  resetInformationObjects(scoreText, livesText, creditsTheme, battleTheme, movementClock);
}

TEST_F(ResetInformationObjectsTest, playsTheBattleTheme)
{
  EXPECT_CALL(battleTheme, play())
      .Times(1);
  resetInformationObjects(scoreText, livesText, creditsTheme, battleTheme, movementClock);
}

TEST_F(ResetInformationObjectsTest, restartsClock)
{
  EXPECT_CALL(movementClock, restart())
      .Times(1);
  resetInformationObjects(scoreText, livesText, creditsTheme, battleTheme, movementClock);
}
