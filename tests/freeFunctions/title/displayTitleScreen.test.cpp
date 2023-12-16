#include "../../../include/title.hpp"
#include "../../mockModels/mockRenderWindow.hpp"
#include "../../mockModels/mockSprite.hpp"
#include "../../mockModels/mockText.hpp"

using ::testing::NiceMock;

class DisplayTitleScreenTest : public testing::Test
{
protected:
  NiceMock<MockRenderWindow> window;
  MockSprite background;
  MockText titleText;
  MockText instructionsText;
};

TEST_F(DisplayTitleScreenTest, clearsTheWindow)
{
  EXPECT_CALL(window, clear())
      .Times(1);
  displayTitleScreen(window, background, titleText, instructionsText);
}

TEST_F(DisplayTitleScreenTest, drawsTheBackgroundImageAndTitleTextAndInstructionsText)
{
  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(3);
  displayTitleScreen(window, background, titleText, instructionsText);
}

TEST_F(DisplayTitleScreenTest, displaysTheWindow)
{
  EXPECT_CALL(window, display())
      .Times(1);
  displayTitleScreen(window, background, titleText, instructionsText);
}
