#include "../../../include/title.hpp"
#include "../../mockModels/mockRenderWindow.hpp"
#include "../../mockModels/mockSprite.hpp"

using ::testing::NiceMock;

TEST(displayTitleScreen, clearsTheWindow)
{
  NiceMock<MockRenderWindow> window;
  MockSprite background;

  EXPECT_CALL(window, clear())
      .Times(1);
  displayTitleScreen(window, background);
}

TEST(displayTitleScreen, drawsTheBackgroundImage)
{
  NiceMock<MockRenderWindow> window;
  MockSprite background;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  displayTitleScreen(window, background);
}
