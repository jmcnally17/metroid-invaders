#include "../include/spaceInvaders.hpp"
#include "./mockModels/mockRenderWindow.hpp"
#include "./mockModels/mockLaserCannon.hpp"

TEST(drawObjects, callsClearOnTheWindow)
{
  MockRenderWindow window;
  MockLaserCannon cannon;

  EXPECT_CALL(window, clear())
      .Times(1);
  drawObjects(window, cannon);
}
