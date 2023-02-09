#include "../../include/spaceInvaders.hpp"
#include "../mockModels/mockInvader.hpp"
#include "../mockModels/mockClock.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(moveInvaders, callsMoveOnInvadersWhenTimeElapsedIsPastIntervalMultipliedByStep)
{
  MockInvader invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(7);
    for (int j = 0; j < 7; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }
  NiceMock<MockClock> clock;
  int interval = 1000;
  int step = 7;
  sf::Time time(sf::milliseconds(7005));

  ON_CALL(clock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(invader, move())
      .Times(14);
  moveInvaders(invaders, clock, interval, step);
}

TEST(moveInvaders, adds1ToTheStepCounterWhenTimeElapsedIsPastIntervalMultipliedByStep)
{
  NiceMock<MockInvader> invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(7);
    for (int j = 0; j < 7; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }
  NiceMock<MockClock> clock;
  int interval = 1000;
  int step = 7;
  sf::Time time(sf::milliseconds(7005));

  ON_CALL(clock, getElapsedTime())
      .WillByDefault(Return(time));

  moveInvaders(invaders, clock, interval, step);
  EXPECT_EQ(step, 8);
}

TEST(moveInvaders, doesNotCallMoveOnInvadersWhenTimeElapsedIsNotPastIntervalMultipliedByStep)
{
  MockInvader invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(7);
    for (int j = 0; j < 7; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }
  NiceMock<MockClock> clock;
  int interval = 1000;
  int step = 7;
  sf::Time time(sf::milliseconds(6995));

  ON_CALL(clock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(invader, move())
      .Times(0);
  moveInvaders(invaders, clock, interval, step);
}

TEST(moveInvaders, doesNotAdd1ToTheStepCounterWhenTimeElapsedIsNotPastIntervalMultipliedByStep)
{
  NiceMock<MockInvader> invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(7);
    for (int j = 0; j < 7; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }
  NiceMock<MockClock> clock;
  int interval = 1000;
  int step = 7;
  sf::Time time(sf::milliseconds(6995));

  ON_CALL(clock, getElapsedTime())
      .WillByDefault(Return(time));

  moveInvaders(invaders, clock, interval, step);
  EXPECT_EQ(step, 7);
}
