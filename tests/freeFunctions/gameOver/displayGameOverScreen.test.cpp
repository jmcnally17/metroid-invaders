#include "../../../include/gameOver.hpp"
#include "../../mockModels/mockRenderWindow.hpp"
#include "../../mockModels/mockText.hpp"

using ::testing::NiceMock;

TEST(displayGameOverScreen, callsClearOnTheWindow)
{
  NiceMock<MockRenderWindow> window;
  MockText gameOverText;
  MockText scoreText;
  MockText playAgainText;

  EXPECT_CALL(window, clear())
      .Times(1);
  displayGameOverScreen(window, gameOverText, scoreText, playAgainText);
}

TEST(displayGameOverScreen, drawsTheGameOverTextAndScoreTextAndPlayAgainText)
{
  NiceMock<MockRenderWindow> window;
  MockText gameOverText;
  MockText scoreText;
  MockText playAgainText;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(3);
  displayGameOverScreen(window, gameOverText, scoreText, playAgainText);
}

TEST(displayGameOverScreen, callsDisplayOnTheWindow)
{
  NiceMock<MockRenderWindow> window;
  MockText gameOverText;
  MockText scoreText;
  MockText playAgainText;

  EXPECT_CALL(window, display())
      .Times(1);
  displayGameOverScreen(window, gameOverText, scoreText, playAgainText);
}
