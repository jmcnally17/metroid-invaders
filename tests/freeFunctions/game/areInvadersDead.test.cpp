#include "../../../include/game.hpp"
#include "../../mockModels/mockInvader.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(areInvadersDead, returnsTrueIfAllInvadersAreDead)
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

  ON_CALL(invader, isAlive)
      .WillByDefault(Return(false));

  EXPECT_TRUE(areInvadersDead(invaders));
}
