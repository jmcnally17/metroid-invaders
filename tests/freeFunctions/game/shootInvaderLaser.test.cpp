#include "../../../include/game.hpp"
#include "../../mockModels/mockInvader.hpp"
#include "../../mockModels/mockLaser.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(shootInvaderLaser, callsShootOnInvadersIfTheyAreAlive)
{
  NiceMock<MockInvader> invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(3);
    for (int j = 0; j < 3; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }
  MockLaser *laser;
  std::vector<ILaser *> lasers(3);
  for (int i = 0; i < 3; i++)
  {
    lasers[i] = laser;
  }

  ON_CALL(invader, isAlive())
      .WillByDefault(Return(true));

  EXPECT_CALL(invader, shoot(lasers))
      .Times(6);
  shootInvaderLaser(invaders, lasers);
}

TEST(shootInvaderLaser, doesNotCallShootOnInvadersIfTheyAreDead)
{
  NiceMock<MockInvader> invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(3);
    for (int j = 0; j < 3; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }
  MockLaser *laser;
  std::vector<ILaser *> lasers(3);
  for (int i = 0; i < 3; i++)
  {
    lasers[i] = laser;
  }

  ON_CALL(invader, isAlive())
      .WillByDefault(Return(false));

  EXPECT_CALL(invader, shoot(lasers))
      .Times(0);
  shootInvaderLaser(invaders, lasers);
}
