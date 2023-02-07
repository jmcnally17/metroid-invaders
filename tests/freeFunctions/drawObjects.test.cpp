#include "../../include/spaceInvaders.hpp"
#include "../mockModels/mockRenderWindow.hpp"
#include "../mockModels/mockLaserCannon.hpp"
#include "../mockModels/mockLaser.hpp"
#include "../mockModels/mockInvader.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(drawObjects, callsClearOnTheWindow)
{
  NiceMock<MockRenderWindow> window;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  NiceMock<MockInvader> invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(5);
  for (int i = 0; i < 5; i++)
  {
    std::vector<IInvader *> invaderRow(11);
    for (int j = 0; j < 11; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }

  EXPECT_CALL(window, clear())
      .Times(1);
  drawObjects(window, cannon, laser, invaders);
}

TEST(drawObjects, callsDrawOnTheLaserCannon)
{
  NiceMock<MockRenderWindow> window;
  MockLaserCannon cannon;
  NiceMock<MockLaser> laser;
  NiceMock<MockInvader> invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(5);
  for (int i = 0; i < 5; i++)
  {
    std::vector<IInvader *> invaderRow(11);
    for (int j = 0; j < 11; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }

  EXPECT_CALL(cannon, draw)
      .Times(1);
  drawObjects(window, cannon, laser, invaders);
}

TEST(drawObjects, callsDrawOnTheLaser)
{
  NiceMock<MockRenderWindow> window;
  NiceMock<MockLaserCannon> cannon;
  MockLaser laser;
  NiceMock<MockInvader> invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(5);
  for (int i = 0; i < 5; i++)
  {
    std::vector<IInvader *> invaderRow(11);
    for (int j = 0; j < 11; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }

  EXPECT_CALL(laser, draw)
      .Times(1);
  drawObjects(window, cannon, laser, invaders);
}

TEST(drawObjects, callsDrawOnAllTheInvadersIfTheyAreAlive)
{
  NiceMock<MockRenderWindow> window;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  NiceMock<MockInvader> invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(5);
  for (int i = 0; i < 5; i++)
  {
    std::vector<IInvader *> invaderRow(11);
    for (int j = 0; j < 11; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }
  ON_CALL(invader, isAlive())
      .WillByDefault(Return(true));

  EXPECT_CALL(invader, draw)
      .Times(55);
  drawObjects(window, cannon, laser, invaders);
}

TEST(drawObjects, doesNotCallDrawOnAllTheInvadersIfTheyAreDead)
{
  NiceMock<MockRenderWindow> window;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  NiceMock<MockInvader> invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(5);
  for (int i = 0; i < 5; i++)
  {
    std::vector<IInvader *> invaderRow(11);
    for (int j = 0; j < 11; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }
  ON_CALL(invader, isAlive())
      .WillByDefault(Return(false));

  EXPECT_CALL(invader, draw)
      .Times(0);
  drawObjects(window, cannon, laser, invaders);
}

TEST(drawObjects, callsDisplayOnTheWindow)
{
  NiceMock<MockRenderWindow> window;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  NiceMock<MockInvader> invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(5);
  for (int i = 0; i < 5; i++)
  {
    std::vector<IInvader *> invaderRow(11);
    for (int j = 0; j < 11; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }

  EXPECT_CALL(window, display())
      .Times(1);
  drawObjects(window, cannon, laser, invaders);
}
