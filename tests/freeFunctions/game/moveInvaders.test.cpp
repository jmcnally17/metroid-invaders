#include "../../../include/game.hpp"
#include "../../mockModels/mockInvader.hpp"
#include "../../mockModels/mockClock.hpp"
#include "../../mockModels/mockSound.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(moveInvaders, callsMoveOnInvadersWhenTimeElapsedIsPastIntervalMultipliedByStep)
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
  NiceMock<MockSound> sound0;
  MockSound *pSound0 = &sound0;
  NiceMock<MockSound> sound1;
  MockSound *pSound1 = &sound1;
  NiceMock<MockSound> sound2;
  MockSound *pSound2 = &sound2;
  NiceMock<MockSound> sound3;
  MockSound *pSound3 = &sound3;
  std::vector<ISound *> sounds = {pSound0, pSound1, pSound2, pSound3};
  int soundCounter = 1;

  ON_CALL(clock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(invader, move())
      .Times(14);
  moveInvaders(invaders, clock, interval, step, sounds, soundCounter);
}

TEST(moveInvaders, doesNotCallMoveOnInvadersWhenTimeElapsedIsNotPastIntervalMultipliedByStep)
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
  NiceMock<MockSound> sound0;
  MockSound *pSound0 = &sound0;
  NiceMock<MockSound> sound1;
  MockSound *pSound1 = &sound1;
  NiceMock<MockSound> sound2;
  MockSound *pSound2 = &sound2;
  NiceMock<MockSound> sound3;
  MockSound *pSound3 = &sound3;
  std::vector<ISound *> sounds = {pSound0, pSound1, pSound2, pSound3};
  int soundCounter = 1;

  ON_CALL(clock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(invader, move())
      .Times(0);
  moveInvaders(invaders, clock, interval, step, sounds, soundCounter);
}

TEST(moveInvaders, adds1ToTheStepCounterWhenTimeElapsedIsPastIntervalMultipliedByStepAndInvadersHaveNotJustMovedDown)
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
  NiceMock<MockSound> sound0;
  MockSound *pSound0 = &sound0;
  NiceMock<MockSound> sound1;
  MockSound *pSound1 = &sound1;
  NiceMock<MockSound> sound2;
  MockSound *pSound2 = &sound2;
  NiceMock<MockSound> sound3;
  MockSound *pSound3 = &sound3;
  std::vector<ISound *> sounds = {pSound0, pSound1, pSound2, pSound3};
  int soundCounter = 1;

  ON_CALL(clock, getElapsedTime())
      .WillByDefault(Return(time));
  ON_CALL(invader, hasJustMovedDown())
      .WillByDefault(Return(false));

  moveInvaders(invaders, clock, interval, step, sounds, soundCounter);
  EXPECT_EQ(step, 8);
}

TEST(moveInvaders, callsRestartOnClockWhenTimeElapsedIsPastIntervalMultipliedByStepAndInvadersHaveJustMovedDown)
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
  NiceMock<MockSound> sound0;
  MockSound *pSound0 = &sound0;
  NiceMock<MockSound> sound1;
  MockSound *pSound1 = &sound1;
  NiceMock<MockSound> sound2;
  MockSound *pSound2 = &sound2;
  NiceMock<MockSound> sound3;
  MockSound *pSound3 = &sound3;
  std::vector<ISound *> sounds = {pSound0, pSound1, pSound2, pSound3};
  int soundCounter = 1;

  ON_CALL(clock, getElapsedTime())
      .WillByDefault(Return(time));
  ON_CALL(invader, hasJustMovedDown())
      .WillByDefault(Return(true));

  EXPECT_CALL(clock, restart())
      .Times(1);
  moveInvaders(invaders, clock, interval, step, sounds, soundCounter);
}

TEST(moveInvaders, decreasesIntervalBy35WhenTimeElapsedIsPastIntervalMultipliedByStepAndInvadersHaveJustMovedDown)
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
  NiceMock<MockSound> sound0;
  MockSound *pSound0 = &sound0;
  NiceMock<MockSound> sound1;
  MockSound *pSound1 = &sound1;
  NiceMock<MockSound> sound2;
  MockSound *pSound2 = &sound2;
  NiceMock<MockSound> sound3;
  MockSound *pSound3 = &sound3;
  std::vector<ISound *> sounds = {pSound0, pSound1, pSound2, pSound3};
  int soundCounter = 1;

  ON_CALL(clock, getElapsedTime())
      .WillByDefault(Return(time));
  ON_CALL(invader, hasJustMovedDown())
      .WillByDefault(Return(true));

  moveInvaders(invaders, clock, interval, step, sounds, soundCounter);
  EXPECT_EQ(interval, 965);
}

TEST(moveInvaders, setsStepCounterTo1WhenTimeElapsedIsPastIntervalMultipliedByStepAndInvadersHaveJustMovedDown)
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
  NiceMock<MockSound> sound0;
  MockSound *pSound0 = &sound0;
  NiceMock<MockSound> sound1;
  MockSound *pSound1 = &sound1;
  NiceMock<MockSound> sound2;
  MockSound *pSound2 = &sound2;
  NiceMock<MockSound> sound3;
  MockSound *pSound3 = &sound3;
  std::vector<ISound *> sounds = {pSound0, pSound1, pSound2, pSound3};
  int soundCounter = 1;

  ON_CALL(clock, getElapsedTime())
      .WillByDefault(Return(time));
  ON_CALL(invader, hasJustMovedDown())
      .WillByDefault(Return(true));

  moveInvaders(invaders, clock, interval, step, sounds, soundCounter);
  EXPECT_EQ(step, 1);
}

TEST(moveInvaders, playsSound0WhenTimeElapsedIsPastIntervalMultipliedByStepAndSoundCounterIs0)
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
  NiceMock<MockSound> sound0;
  MockSound *pSound0 = &sound0;
  NiceMock<MockSound> sound1;
  MockSound *pSound1 = &sound1;
  NiceMock<MockSound> sound2;
  MockSound *pSound2 = &sound2;
  NiceMock<MockSound> sound3;
  MockSound *pSound3 = &sound3;
  std::vector<ISound *> sounds = {pSound0, pSound1, pSound2, pSound3};
  int soundCounter = 0;

  ON_CALL(clock, getElapsedTime())
      .WillByDefault(Return(time));
  ON_CALL(invader, hasJustMovedDown())
      .WillByDefault(Return(true));

  EXPECT_CALL(sound0, play())
      .Times(1);
  moveInvaders(invaders, clock, interval, step, sounds, soundCounter);
}

TEST(moveInvaders, playsSound1WhenTimeElapsedIsPastIntervalMultipliedByStepAndSoundCounterIs1)
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
  NiceMock<MockSound> sound0;
  MockSound *pSound0 = &sound0;
  NiceMock<MockSound> sound1;
  MockSound *pSound1 = &sound1;
  NiceMock<MockSound> sound2;
  MockSound *pSound2 = &sound2;
  NiceMock<MockSound> sound3;
  MockSound *pSound3 = &sound3;
  std::vector<ISound *> sounds = {pSound0, pSound1, pSound2, pSound3};
  int soundCounter = 1;

  ON_CALL(clock, getElapsedTime())
      .WillByDefault(Return(time));
  ON_CALL(invader, hasJustMovedDown())
      .WillByDefault(Return(true));

  EXPECT_CALL(sound1, play())
      .Times(1);
  moveInvaders(invaders, clock, interval, step, sounds, soundCounter);
}

TEST(moveInvaders, playsSound2WhenTimeElapsedIsPastIntervalMultipliedByStepAndSoundCounterIs2)
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
  NiceMock<MockSound> sound0;
  MockSound *pSound0 = &sound0;
  NiceMock<MockSound> sound1;
  MockSound *pSound1 = &sound1;
  NiceMock<MockSound> sound2;
  MockSound *pSound2 = &sound2;
  NiceMock<MockSound> sound3;
  MockSound *pSound3 = &sound3;
  std::vector<ISound *> sounds = {pSound0, pSound1, pSound2, pSound3};
  int soundCounter = 2;

  ON_CALL(clock, getElapsedTime())
      .WillByDefault(Return(time));
  ON_CALL(invader, hasJustMovedDown())
      .WillByDefault(Return(true));

  EXPECT_CALL(sound2, play())
      .Times(1);
  moveInvaders(invaders, clock, interval, step, sounds, soundCounter);
}

TEST(moveInvaders, playsSound3WhenTimeElapsedIsPastIntervalMultipliedByStepAndSoundCounterIs3)
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
  NiceMock<MockSound> sound0;
  MockSound *pSound0 = &sound0;
  NiceMock<MockSound> sound1;
  MockSound *pSound1 = &sound1;
  NiceMock<MockSound> sound2;
  MockSound *pSound2 = &sound2;
  NiceMock<MockSound> sound3;
  MockSound *pSound3 = &sound3;
  std::vector<ISound *> sounds = {pSound0, pSound1, pSound2, pSound3};
  int soundCounter = 3;

  ON_CALL(clock, getElapsedTime())
      .WillByDefault(Return(time));
  ON_CALL(invader, hasJustMovedDown())
      .WillByDefault(Return(true));

  EXPECT_CALL(sound3, play())
      .Times(1);
  moveInvaders(invaders, clock, interval, step, sounds, soundCounter);
}

TEST(moveInvaders, increasesSoundCounterBy1WhenTimeElapsedIsPastInterval)
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
  NiceMock<MockSound> sound0;
  MockSound *pSound0 = &sound0;
  NiceMock<MockSound> sound1;
  MockSound *pSound1 = &sound1;
  NiceMock<MockSound> sound2;
  MockSound *pSound2 = &sound2;
  NiceMock<MockSound> sound3;
  MockSound *pSound3 = &sound3;
  std::vector<ISound *> sounds = {pSound0, pSound1, pSound2, pSound3};
  int soundCounter = 26;

  ON_CALL(clock, getElapsedTime())
      .WillByDefault(Return(time));
  ON_CALL(invader, hasJustMovedDown())
      .WillByDefault(Return(true));

  moveInvaders(invaders, clock, interval, step, sounds, soundCounter);
  EXPECT_EQ(soundCounter, 27);
}
