#include "../include/spaceInvaders.hpp"
#include "./mockModels/mockRenderWindow.hpp"
#include "./mockModels/mockLaserCannon.hpp"

using ::testing::NiceMock;

TEST(drawObjects, callsClearOnTheWindow)
{
  NiceMock<MockRenderWindow> window;
  NiceMock<MockLaserCannon> cannon;

  EXPECT_CALL(window, clear())
      .Times(1);
  drawObjects(window, cannon);
}

TEST(drawObjects, callsDrawOnTheLaserCannon)
{
  NiceMock<MockRenderWindow> window;
  MockLaserCannon cannon;

  EXPECT_CALL(cannon, draw)
      .Times(1);
  drawObjects(window, cannon);
}

TEST(drawObjects, callsDisplayOnTheWindow)
{
  NiceMock<MockRenderWindow> window;
  NiceMock<MockLaserCannon> cannon;

  EXPECT_CALL(window, display())
      .Times(1);
  drawObjects(window, cannon);
}
