#include "../../../include/GameOver.hpp"
#include "../../mockModels/MockRenderWindow.hpp"
#include "../../mockModels/MockText.hpp"

using ::testing::NiceMock;

class DisplayGameOverScreenTest : public testing::Test
{
protected:
  NiceMock<MockRenderWindow> window;
  MockText gameOverText;
  MockText scoreText;
  MockText playAgainText;
};

TEST_F(DisplayGameOverScreenTest, callsClearOnTheWindow)
{
  EXPECT_CALL(window, clear())
      .Times(1);
  displayGameOverScreen(window, gameOverText, scoreText, playAgainText);
}

TEST_F(DisplayGameOverScreenTest, drawsTheGameOverTextAndScoreTextAndPlayAgainText)
{
  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(3);
  displayGameOverScreen(window, gameOverText, scoreText, playAgainText);
}

TEST_F(DisplayGameOverScreenTest, callsDisplayOnTheWindow)
{
  EXPECT_CALL(window, display())
      .Times(1);
  displayGameOverScreen(window, gameOverText, scoreText, playAgainText);
}
