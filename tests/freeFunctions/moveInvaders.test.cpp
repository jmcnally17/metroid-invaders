#include "../../include/spaceInvaders.hpp"
#include "../mockModels/mockInvader.hpp"
#include "../mockModels/mockClock.hpp"

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
  MockClock clock;
  int interval = 1000;
  int step = 7;
  sf::Time time(sf::milliseconds(7005));

  ON_CALL(clock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(invader, move())
      .Times(14);
  moveInvaders(invaders, clock, interval, step);
}
