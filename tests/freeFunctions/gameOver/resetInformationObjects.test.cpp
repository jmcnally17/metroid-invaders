#include "../../../include/GameOver.hpp"
#include "../../mockModels/MockText.hpp"
#include "../../mockModels/MockSound.hpp"
#include "../../mockModels/MockClock.hpp"

using ::testing::NiceMock;

class ResetInformationObjectsTest : public testing::Test
{
protected:
  NiceMock<MockText> scoreText;
  MockText *pScoreText {&scoreText};
  NiceMock<MockText> livesText;
  MockText *pLivesText {&livesText};
  std::unordered_map<std::string, IText*> textObjects {
    {"score", pScoreText},
    {"lives", pLivesText},
  };
  NiceMock<MockSound> creditsTheme;
  MockSound *pCreditsTheme {&creditsTheme};
  NiceMock<MockSound> battleTheme;
  MockSound *pBattleTheme {&battleTheme};
  std::unordered_map<std::string, ISound*> themes {
    {"credits", pCreditsTheme},
    {"battle", pBattleTheme},
  };
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
  resetInformationObjects(textObjects, themes, movementClock);
}

TEST_F(ResetInformationObjectsTest, updatesLivesText)
{
  EXPECT_CALL(livesText, setString("Lives: 3"))
      .Times(1);
  resetInformationObjects(textObjects, themes, movementClock);
}

TEST_F(ResetInformationObjectsTest, stopsTheCreditsTheme)
{
  EXPECT_CALL(creditsTheme, stop())
      .Times(1);
  resetInformationObjects(textObjects, themes, movementClock);
}

TEST_F(ResetInformationObjectsTest, playsTheBattleTheme)
{
  EXPECT_CALL(battleTheme, play())
      .Times(1);
  resetInformationObjects(textObjects, themes, movementClock);
}

TEST_F(ResetInformationObjectsTest, restartsClock)
{
  EXPECT_CALL(movementClock, restart())
      .Times(1);
  resetInformationObjects(textObjects, themes, movementClock);
}
