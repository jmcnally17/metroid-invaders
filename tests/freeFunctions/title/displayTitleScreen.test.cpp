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

  EXPECT_CALL(window, clear())
      .Times(1);
  displayTitleScreen(window, background, titleText);
}

TEST(displayTitleScreen, drawsTheBackgroundImageAndTitleText)
{
  NiceMock<MockRenderWindow> window;
  MockSprite background;
  MockText titleText;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(2);
  displayTitleScreen(window, background, titleText);
}
