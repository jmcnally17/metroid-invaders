#include "../../../include/title.hpp"
#include "../../mockModels/mockRenderWindow.hpp"
#include "../../mockModels/mockSprite.hpp"
#include "../../mockModels/mockText.hpp"

using ::testing::NiceMock;

TEST(displayTitleScreen, clearsTheWindow)
{
  NiceMock<MockRenderWindow> window;
  MockSprite background;
  MockText titleText;
  MockText instructionsText;

  EXPECT_CALL(window, clear())
      .Times(1);
  displayTitleScreen(window, background, titleText, instructionsText);
}

TEST(displayTitleScreen, drawsTheBackgroundImageAndTitleTextAndInstructionsText)
{
  NiceMock<MockRenderWindow> window;
  MockSprite background;
  MockText titleText;
  MockText instructionsText;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(3);
  displayTitleScreen(window, background, titleText, instructionsText);
}

TEST(displayTitleScreen, displaysTheWindow)
{
  NiceMock<MockRenderWindow> window;
  MockSprite background;
  MockText titleText;
  MockText instructionsText;

  EXPECT_CALL(window, display())
      .Times(1);
  displayTitleScreen(window, background, titleText, instructionsText);
}
