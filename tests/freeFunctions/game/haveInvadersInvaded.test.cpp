#include <vector>
#include "../../../include/game.hpp"
#include "../../mockModels/mockInvader.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(haveInvadersInvaded, returnsTrueIfAnInvaderHasReachedTheBottomAndIsAlive)
{
  NiceMock<MockInvader> invader1;
  MockInvader *pInvader1 = &invader1;
  NiceMock<MockInvader> invader2;
  MockInvader *pInvader2 = &invader2;
  std::vector<std::vector<IInvader *>> invaders(2);

  std::vector<IInvader *> invaderRow1(2);
  invaderRow1[0] = pInvader2;
  invaderRow1[1] = pInvader2;
  invaders[0] = invaderRow1;
  std::vector<IInvader *> invaderRow2(2);
  invaderRow2[0] = pInvader1;
  invaderRow2[1] = pInvader2;
  invaders[1] = invaderRow2;

  ON_CALL(invader1, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 1128)));
  ON_CALL(invader2, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 900)));
  ON_CALL(invader1, isAlive)
      .WillByDefault(Return(true));
  ON_CALL(invader2, isAlive)
      .WillByDefault(Return(false));

  EXPECT_TRUE(haveInvadersInvaded(invaders));
}

TEST(haveInvadersInvaded, returnsfalseIfInvadersHaveNotReachedTheBottomAndAreAlive)
{
  NiceMock<MockInvader> invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(2);

  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(2);
    for (int j = 0; j < 2; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }

  ON_CALL(invader, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 900)));
  ON_CALL(invader, isAlive)
      .WillByDefault(Return(true));

  EXPECT_FALSE(haveInvadersInvaded(invaders));
}

TEST(haveInvadersInvaded, returnsfalseIfInvadersHaveReachedTheBottomButAreDead)
{
  NiceMock<MockInvader> invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(2);

  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(2);
    for (int j = 0; j < 2; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }

  ON_CALL(invader, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 1128)));
  ON_CALL(invader, isAlive)
      .WillByDefault(Return(false));

  EXPECT_FALSE(haveInvadersInvaded(invaders));
}
