#include "../../../include/Title.hpp"
#include "../../mockModels/MockRenderWindow.hpp"
#include "../../mockModels/MockSprite.hpp"
#include "../../mockModels/MockText.hpp"

using ::testing::NiceMock;

class DisplayTitleScreenTest : public testing::Test
{
protected:
  NiceMock<MockRenderWindow> window;
  MockSprite titleBackground;
  MockSprite *pTitleBackground {&titleBackground};
  std::unordered_map<std::string, ISprite*> backgrounds {
    {"title", pTitleBackground},
  };
  MockText titleText;
  MockText *pTitleText {&titleText};
  MockText instructionsText;
  MockText *pInstructionsText {&instructionsText};
  std::unordered_map<std::string, IText*> textObjects {
    {"title", pTitleText},
    {"instructions", pInstructionsText},
  };
};

TEST_F(DisplayTitleScreenTest, clearsTheWindow)
{
  EXPECT_CALL(window, clear())
      .Times(1);
  displayTitleScreen(window, backgrounds, textObjects);
}

TEST_F(DisplayTitleScreenTest, drawsTheBackgroundImageAndTitleTextAndInstructionsText)
{
  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(3);
  displayTitleScreen(window, backgrounds, textObjects);
}

TEST_F(DisplayTitleScreenTest, displaysTheWindow)
{
  EXPECT_CALL(window, display())
      .Times(1);
  displayTitleScreen(window, backgrounds, textObjects);
}
