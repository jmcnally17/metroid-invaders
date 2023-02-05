#include "../include/spaceInvaders.hpp"
#include "./mockModels/mockRenderWindow.hpp"
#include "./mockModels/mockLaserCannon.hpp"
#include "./mockModels/mockLaser.hpp"
#include "./mockModels/mockInvader.hpp"

using ::testing::NiceMock;

TEST(drawObjects, callsClearOnTheWindow)
{
  NiceMock<MockRenderWindow> window;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  NiceMock<MockInvader> invader;

  EXPECT_CALL(window, clear())
      .Times(1);
  drawObjects(window, cannon, laser, invader);
}

TEST(drawObjects, callsDrawOnTheLaserCannon)
{
  NiceMock<MockRenderWindow> window;
  MockLaserCannon cannon;
  NiceMock<MockLaser> laser;
  NiceMock<MockInvader> invader;

  EXPECT_CALL(cannon, draw)
      .Times(1);
  drawObjects(window, cannon, laser, invader);
}

TEST(drawObjects, callsDrawOnTheLaser)
{
  NiceMock<MockRenderWindow> window;
  NiceMock<MockLaserCannon> cannon;
  MockLaser laser;
  NiceMock<MockInvader> invader;

  EXPECT_CALL(laser, draw)
      .Times(1);
  drawObjects(window, cannon, laser, invader);
}

TEST(drawObjects, callsDrawOnTheInvader)
{
  NiceMock<MockRenderWindow> window;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  MockInvader invader;

  EXPECT_CALL(invader, draw)
      .Times(1);
  drawObjects(window, cannon, laser, invader);
}

TEST(drawObjects, callsDisplayOnTheWindow)
{
  NiceMock<MockRenderWindow> window;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  NiceMock<MockInvader> invader;

  EXPECT_CALL(window, display())
      .Times(1);
  drawObjects(window, cannon, laser, invader);
}
