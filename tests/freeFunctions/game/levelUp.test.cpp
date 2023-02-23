#include "../../../include/game.hpp"
#include "../../mockModels/mockInvader.hpp"
#include "../../mockModels/mockLaser.hpp"
#include "../../mockModels/mockClock.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(levelUp, adds1ToTheLevelVariable)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
  MockInvader *invader = new NiceMock<MockInvader>();
  std::vector<std::vector<IInvader *>> invaders(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(4);
    for (int j = 0; j < 4; j++)
    {
      invaderRow[j] = invader;
    }
    invaders[i] = invaderRow;
  }
  MockLaser *laser = new NiceMock<MockLaser>();
  std::vector<ILaser *> invaderLasers(3);
  for (int i = 0; i < 3; i++)
  {
    invaderLasers[i] = laser;
  }
  NiceMock<MockClock> clock;

  levelUp(level, interval, step, soundCounter, invaders, invaderLasers, clock);
  EXPECT_EQ(level, 6);
}

TEST(levelUp, resetsTheInterval)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
  MockInvader *invader = new NiceMock<MockInvader>();
  std::vector<std::vector<IInvader *>> invaders(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(4);
    for (int j = 0; j < 4; j++)
    {
      invaderRow[j] = invader;
    }
    invaders[i] = invaderRow;
  }
  MockLaser *laser = new NiceMock<MockLaser>();
  std::vector<ILaser *> invaderLasers(3);
  for (int i = 0; i < 3; i++)
  {
    invaderLasers[i] = laser;
  }
  NiceMock<MockClock> clock;

  levelUp(level, interval, step, soundCounter, invaders, invaderLasers, clock);
  EXPECT_EQ(interval, 665);
}

TEST(levelUp, resetsTheStepCounter)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
  MockInvader *invader = new NiceMock<MockInvader>();
  std::vector<std::vector<IInvader *>> invaders(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(4);
    for (int j = 0; j < 4; j++)
    {
      invaderRow[j] = invader;
    }
    invaders[i] = invaderRow;
  }
  MockLaser *laser = new NiceMock<MockLaser>();
  std::vector<ILaser *> invaderLasers(3);
  for (int i = 0; i < 3; i++)
  {
    invaderLasers[i] = laser;
  }
  NiceMock<MockClock> clock;

  levelUp(level, interval, step, soundCounter, invaders, invaderLasers, clock);
  EXPECT_EQ(step, 1);
}

TEST(levelUp, resetsTheSoundCounter)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
  MockInvader *invader = new NiceMock<MockInvader>();
  std::vector<std::vector<IInvader *>> invaders(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(4);
    for (int j = 0; j < 4; j++)
    {
      invaderRow[j] = invader;
    }
    invaders[i] = invaderRow;
  }
  MockLaser *laser = new NiceMock<MockLaser>();
  std::vector<ILaser *> invaderLasers(3);
  for (int i = 0; i < 3; i++)
  {
    invaderLasers[i] = laser;
  }
  NiceMock<MockClock> clock;

  levelUp(level, interval, step, soundCounter, invaders, invaderLasers, clock);
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
  MockLaser *laser = new NiceMock<MockLaser>();
  std::vector<ILaser *> invaderLasers(3);
  for (int i = 0; i < 3; i++)
  {
    invaderLasers[i] = laser;
  }
  NiceMock<MockClock> clock;

  EXPECT_CALL(invader, resurrect())
      .Times(8);
  levelUp(level, interval, step, soundCounter, invaders, invaderLasers, clock);
}

TEST(levelUp, changesDirectionOnInvadersIfTheyAreMovingLeft)
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
  MockLaser *laser = new NiceMock<MockLaser>();
  std::vector<ILaser *> invaderLasers(3);
  for (int i = 0; i < 3; i++)
  {
    invaderLasers[i] = laser;
  }
  NiceMock<MockClock> clock;

  ON_CALL(invader, getDirection())
      .WillByDefault(Return(-1));

  EXPECT_CALL(invader, changeDirection())
      .Times(8);
  levelUp(level, interval, step, soundCounter, invaders, invaderLasers, clock);
}

TEST(levelUp, doesNotChangeDirectionOnInvadersIfTheyAreMovingRight)
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
  MockLaser *laser = new NiceMock<MockLaser>();
  std::vector<ILaser *> invaderLasers(3);
  for (int i = 0; i < 3; i++)
  {
    invaderLasers[i] = laser;
  }
  NiceMock<MockClock> clock;

  ON_CALL(invader, getDirection())
      .WillByDefault(Return(1));

  EXPECT_CALL(invader, changeDirection())
      .Times(0);
  levelUp(level, interval, step, soundCounter, invaders, invaderLasers, clock);
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
  MockLaser *laser = new NiceMock<MockLaser>();
  std::vector<ILaser *> invaderLasers(3);
  for (int i = 0; i < 3; i++)
  {
    invaderLasers[i] = laser;
  }
  NiceMock<MockClock> clock;

  ON_CALL(invader, getOriginalPosition())
      .WillByDefault(Return(sf::Vector2f(400, 960)));

  EXPECT_CALL(invader, setPosition(sf::Vector2f(400, 1170)))
      .Times(8);
  levelUp(level, interval, step, soundCounter, invaders, invaderLasers, clock);
}

TEST(levelUp, resetsTheInvaderLasers)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
  MockInvader *invader = new NiceMock<MockInvader>();
  std::vector<std::vector<IInvader *>> invaders(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(4);
    for (int j = 0; j < 4; j++)
    {
      invaderRow[j] = invader;
    }
    invaders[i] = invaderRow;
  }
  MockLaser laser;
  MockLaser *pLaser = &laser;
  std::vector<ILaser *> invaderLasers(3);
  for (int i = 0; i < 3; i++)
  {
    invaderLasers[i] = pLaser;
  }
  NiceMock<MockClock> clock;

  EXPECT_CALL(laser, reset())
      .Times(3);
  levelUp(level, interval, step, soundCounter, invaders, invaderLasers, clock);
}

TEST(levelUp, restartsTheClock)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
  MockInvader *invader = new NiceMock<MockInvader>();
  std::vector<std::vector<IInvader *>> invaders(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(4);
    for (int j = 0; j < 4; j++)
    {
      invaderRow[j] = invader;
    }
    invaders[i] = invaderRow;
  }
  MockLaser *laser = new NiceMock<MockLaser>();
  std::vector<ILaser *> invaderLasers(3);
  for (int i = 0; i < 3; i++)
  {
    invaderLasers[i] = laser;
  }
  MockClock clock;

  EXPECT_CALL(clock, restart())
      .Times(1);
  levelUp(level, interval, step, soundCounter, invaders, invaderLasers, clock);
}
