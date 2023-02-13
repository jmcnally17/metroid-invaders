#include <vector>
#include "../../../include/gameOver.hpp"
#include "../../mockModels/mockLaserCannon.hpp"
#include "../../mockModels/mockLaser.hpp"
#include "../../mockModels/mockInvader.hpp"

using ::testing::NiceMock;

TEST(playAgain, setsIsPlayingToTrue)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  std::vector<std::vector<IInvader *>> invaders;

  playAgain(isPlaying, gameOver, cannon, laser, invaders);
  EXPECT_EQ(isPlaying, true);
}

TEST(playAgain, setsGameOverToFalse)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  std::vector<std::vector<IInvader *>> invaders;

  playAgain(isPlaying, gameOver, cannon, laser, invaders);
  EXPECT_EQ(gameOver, false);
}

TEST(playAgain, resetsTheLaserCannon)
{
  bool isPlaying = false;
  bool gameOver = true;
  MockLaserCannon cannon;
  NiceMock<MockLaser> laser;
  std::vector<std::vector<IInvader *>> invaders;

  EXPECT_CALL(cannon, reset())
      .Times(1);
  playAgain(isPlaying, gameOver, cannon, laser, invaders);
}

TEST(playAgain, resetsTheLaser)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  MockLaser laser;
  std::vector<std::vector<IInvader *>> invaders;

  EXPECT_CALL(laser, reset())
      .Times(1);
  playAgain(isPlaying, gameOver, cannon, laser, invaders);
}

TEST(playAgain, resetsTheInvaders)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  MockInvader invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(6);
    for (int j = 0; j < 6; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }

  EXPECT_CALL(invader, reset())
      .Times(12);
  playAgain(isPlaying, gameOver, cannon, laser, invaders);
}
