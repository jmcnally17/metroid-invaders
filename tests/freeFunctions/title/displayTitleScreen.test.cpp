#include "../../../include/title.hpp"
#include "../../mockModels/mockRenderWindow.hpp"

TEST(displayTitleScreen, clearsTheWindow)
{
  MockRenderWindow window;

  EXPECT_CALL(window, clear())
      .Times(1);
  displayTitleScreen(window);
}
