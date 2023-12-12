#include "../../../../include/game.hpp"
#include "../../../mockModels/mockMetroid.hpp"
#include "../../../mockModels/mockClock.hpp"
#include "../../../mockModels/mockSound.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(moveMetroids, callsMoveOnMetroidsWhenTimeElapsedIsPastIntervalMultipliedByStep)
{
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(7);
    for (int j = 0; j < 7; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  NiceMock<MockClock> movementClock;
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
  std::unordered_map<std::string, int> variables = {
    {"interval", 1000},
    {"step", 7},
    {"soundCounter", 1},
  };

  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(metroid, move())
      .Times(14);
  moveMetroids(metroids, movementClock, variables, sounds);
}

TEST(moveMetroids, doesNotCallMoveOnMetroidsWhenTimeElapsedIsNotPastIntervalMultipliedByStep)
{
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(7);
    for (int j = 0; j < 7; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  NiceMock<MockClock> movementClock;
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
  std::unordered_map<std::string, int> variables = {
    {"interval", 1000},
    {"step", 7},
    {"soundCounter", 1},
  };

  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(metroid, move())
      .Times(0);
  moveMetroids(metroids, movementClock, variables, sounds);
}

TEST(moveMetroids, adds1ToTheStepCounterWhenTimeElapsedIsPastIntervalMultipliedByStepAndMetroidsHaveNotJustMovedDown)
{
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(7);
    for (int j = 0; j < 7; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  NiceMock<MockClock> movementClock;
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
  std::unordered_map<std::string, int> variables = {
    {"interval", 1000},
    {"step", 7},
    {"soundCounter", 1},
  };

  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));
  ON_CALL(metroid, hasJustMovedDown())
      .WillByDefault(Return(false));

  moveMetroids(metroids, movementClock, variables, sounds);
  EXPECT_EQ(variables["step"], 8);
}

TEST(moveMetroids, callsRestartOnClockWhenTimeElapsedIsPastIntervalMultipliedByStepAndMetroidsHaveJustMovedDown)
{
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(7);
    for (int j = 0; j < 7; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  NiceMock<MockClock> movementClock;
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
  std::unordered_map<std::string, int> variables = {
    {"interval", 1000},
    {"step", 7},
    {"soundCounter", 1},
  };

  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));
  ON_CALL(metroid, hasJustMovedDown())
      .WillByDefault(Return(true));

  EXPECT_CALL(movementClock, restart())
      .Times(1);
  moveMetroids(metroids, movementClock, variables, sounds);
}

TEST(moveMetroids, decreasesIntervalBy35WhenTimeElapsedIsPastIntervalMultipliedByStepAndMetroidsHaveJustMovedDown)
{
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(7);
    for (int j = 0; j < 7; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  NiceMock<MockClock> movementClock;
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
  std::unordered_map<std::string, int> variables = {
    {"interval", 1000},
    {"step", 7},
    {"soundCounter", 1},
  };

  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));
  ON_CALL(metroid, hasJustMovedDown())
      .WillByDefault(Return(true));

  moveMetroids(metroids, movementClock, variables, sounds);
  EXPECT_EQ(variables["interval"], 965);
}

TEST(moveMetroids, setsStepCounterTo1WhenTimeElapsedIsPastIntervalMultipliedByStepAndMetroidsHaveJustMovedDown)
{
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(7);
    for (int j = 0; j < 7; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  NiceMock<MockClock> movementClock;
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
  std::unordered_map<std::string, int> variables = {
    {"interval", 1000},
    {"step", 7},
    {"soundCounter", 1},
  };

  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));
  ON_CALL(metroid, hasJustMovedDown())
      .WillByDefault(Return(true));

  moveMetroids(metroids, movementClock, variables, sounds);
  EXPECT_EQ(variables["step"], 1);
}

TEST(moveMetroids, playsSound0WhenTimeElapsedIsPastIntervalMultipliedByStepAndSoundCounterIs0)
{
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(7);
    for (int j = 0; j < 7; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  NiceMock<MockClock> movementClock;
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
  std::unordered_map<std::string, int> variables = {
    {"interval", 1000},
    {"step", 7},
    {"soundCounter", 0},
  };

  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(sound0, play())
      .Times(1);
  moveMetroids(metroids, movementClock, variables, sounds);
}

TEST(moveMetroids, playsSound1WhenTimeElapsedIsPastIntervalMultipliedByStepAndSoundCounterIs1)
{
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(7);
    for (int j = 0; j < 7; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  NiceMock<MockClock> movementClock;
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
  std::unordered_map<std::string, int> variables = {
    {"interval", 1000},
    {"step", 7},
    {"soundCounter", 1},
  };

  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(sound1, play())
      .Times(1);
  moveMetroids(metroids, movementClock, variables, sounds);
}

TEST(moveMetroids, playsSound2WhenTimeElapsedIsPastIntervalMultipliedByStepAndSoundCounterIs2)
{
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(7);
    for (int j = 0; j < 7; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  NiceMock<MockClock> movementClock;
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
  std::unordered_map<std::string, int> variables = {
    {"interval", 1000},
    {"step", 7},
    {"soundCounter", 2},
  };

  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(sound2, play())
      .Times(1);
  moveMetroids(metroids, movementClock, variables, sounds);
}

TEST(moveMetroids, playsSound3WhenTimeElapsedIsPastIntervalMultipliedByStepAndSoundCounterIs3)
{
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(7);
    for (int j = 0; j < 7; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  NiceMock<MockClock> movementClock;
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
  std::unordered_map<std::string, int> variables = {
    {"interval", 1000},
    {"step", 7},
    {"soundCounter", 3},
  };

  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(sound3, play())
      .Times(1);
  moveMetroids(metroids, movementClock, variables, sounds);
}

TEST(moveMetroids, increasesSoundCounterBy1WhenTimeElapsedIsPastInterval)
{
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(7);
    for (int j = 0; j < 7; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  NiceMock<MockClock> movementClock;
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
  std::unordered_map<std::string, int> variables = {
    {"interval", 1000},
    {"step", 7},
    {"soundCounter", 26},
  };

  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));

  moveMetroids(metroids, movementClock, variables, sounds);
  EXPECT_EQ(variables["soundCounter"], 27);
}
