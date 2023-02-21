#include "../../../include/game.hpp"
#include "../../mockModels/mockInvader.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(levelUp, adds1ToTheLevelVariable)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
  NiceMock<MockInvader> invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(4);
    for (int j = 0; j < 4; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }

  levelUp(level, interval, step, soundCounter, invaders);
  EXPECT_EQ(level, 6);
}

TEST(levelUp, resetsTheInterval)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
  NiceMock<MockInvader> invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(4);
    for (int j = 0; j < 4; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }

  levelUp(level, interval, step, soundCounter, invaders);
  EXPECT_EQ(interval, 665);
}

TEST(levelUp, resetsTheStepCounter)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
  NiceMock<MockInvader> invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(4);
    for (int j = 0; j < 4; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }

  levelUp(level, interval, step, soundCounter, invaders);
  EXPECT_EQ(step, 1);
}

TEST(levelUp, resetsTheSoundCounter)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
  NiceMock<MockInvader> invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(4);
    for (int j = 0; j < 4; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }

  levelUp(level, interval, step, soundCounter, invaders);
  EXPECT_EQ(soundCounter, 0);
}

TEST(levelUp, callsResurrectOnEachInvader)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
  NiceMock<MockInvader> invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(4);
    for (int j = 0; j < 4; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }

  EXPECT_CALL(invader, resurrect())
      .Times(8);
  levelUp(level, interval, step, soundCounter, invaders);
}

TEST(levelUp, setsNextLevelPositionOnInvaders)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
  NiceMock<MockInvader> invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(4);
    for (int j = 0; j < 4; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }

  ON_CALL(invader, getOriginalPosition())
      .WillByDefault(Return(sf::Vector2f(400, 960)));

  EXPECT_CALL(invader, setPosition(sf::Vector2f(400, 1170)))
      .Times(8);
  levelUp(level, interval, step, soundCounter, invaders);
}
