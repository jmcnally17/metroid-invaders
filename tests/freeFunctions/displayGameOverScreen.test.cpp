#include "../../include/spaceInvaders.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;

TEST(displayGameOverScreen, callsClearOnTheWindow)
{
  NiceMock<MockRenderWindow> window;

  EXPECT_CALL(window, clear())
      .Times(1);
  displayGameOverScreen(window);
}

TEST(displayGameOverScreen, callsDisplayOnTheWindow)
{
  NiceMock<MockRenderWindow> window;

  EXPECT_CALL(window, display())
      .Times(1);
  displayGameOverScreen(window);
}
