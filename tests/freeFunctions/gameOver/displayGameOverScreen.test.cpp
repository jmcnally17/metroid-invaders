#include "../../../include/GameOver.hpp"
#include "../../mockModels/MockRenderWindow.hpp"
#include "../../mockModels/MockText.hpp"

using ::testing::NiceMock;

class DisplayGameOverScreenTest : public testing::Test
{
protected:
  NiceMock<MockRenderWindow> window;
  MockText gameOverText;
  MockText *pGameOverText {&gameOverText};
  MockText scoreText;
  MockText *pScoreText {&scoreText};
  MockText playAgainText;
  MockText *pPlayAgainText {&playAgainText};
  std::unordered_map<std::string, IText*> textObjects {
    {"gameOver", pGameOverText},
    {"score", pScoreText},
    {"playAgain", pPlayAgainText},
  };
};

TEST_F(DisplayGameOverScreenTest, callsClearOnTheWindow)
{
  EXPECT_CALL(window, clear())
      .Times(1);
  displayGameOverScreen(window, textObjects);
}

TEST_F(DisplayGameOverScreenTest, drawsTheGameOverTextAndScoreTextAndPlayAgainText)
{
  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(3);
  displayGameOverScreen(window, textObjects);
}

TEST_F(DisplayGameOverScreenTest, callsDisplayOnTheWindow)
{
  EXPECT_CALL(window, display())
      .Times(1);
  displayGameOverScreen(window, textObjects);
}
