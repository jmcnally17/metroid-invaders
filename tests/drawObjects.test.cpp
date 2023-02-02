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

TEST(drawObjects, callsDrawOnTheLaserCannon)
{
  MockRenderWindow window;
  MockLaserCannon cannon;

  EXPECT_CALL(cannon, draw)
      .Times(1);
  drawObjects(window, cannon);
}

TEST(drawObjects, callsDisplayOnTheWindow)
{
  MockRenderWindow window;
  MockLaserCannon cannon;

  EXPECT_CALL(window, display())
      .Times(1);
  drawObjects(window, cannon);
}
