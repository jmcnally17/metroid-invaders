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

TEST(areInvadersDead, returnsFalseIfAnyInvadersAreAlive)
{
  NiceMock<MockInvader> invader1;
  MockInvader *pInvader1 = &invader1;
  NiceMock<MockInvader> invader2;
  MockInvader *pInvader2 = &invader2;
  std::vector<std::vector<IInvader *>> invaders(2);
  std::vector<IInvader *> invaderRow1(2);
  invaderRow1[0] = pInvader1;
  invaderRow1[1] = pInvader1;
  std::vector<IInvader *> invaderRow2(2);
  invaderRow2[0] = pInvader2;
  invaderRow2[1] = pInvader1;
  invaders[0] = invaderRow1;
  invaders[1] = invaderRow2;

  ON_CALL(invader1, isAlive)
      .WillByDefault(Return(false));
  ON_CALL(invader1, isAlive)
      .WillByDefault(Return(true));

  EXPECT_FALSE(areInvadersDead(invaders));
}
