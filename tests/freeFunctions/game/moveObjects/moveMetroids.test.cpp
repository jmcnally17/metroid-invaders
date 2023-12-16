#include "../../../../include/game.hpp"
#include "../../../mockModels/mockMetroid.hpp"
#include "../../../mockModels/mockClock.hpp"
#include "../../../mockModels/mockSound.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class MoveMetroidsTest : public testing::Test
{
protected:
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid {&metroid};
  std::array<std::array<IMetroid*, 11>, 5> metroids {{
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
  }};
  NiceMock<MockClock> movementClock;
  sf::Time time {sf::Time(sf::milliseconds(7005))};
  NiceMock<MockSound> sound0;
  MockSound *pSound0 {&sound0};
  NiceMock<MockSound> sound1;
  MockSound *pSound1 {&sound1};
  NiceMock<MockSound> sound2;
  MockSound *pSound2 {&sound2};
  NiceMock<MockSound> sound3;
  MockSound *pSound3 {&sound3};
  std::array<ISound*, 4> sounds {pSound0, pSound1, pSound2, pSound3};
  std::unordered_map<std::string, int> variables {
    {"interval", 1000},
    {"step", 7},
    {"soundCounter", 1},
  };
};

TEST_F(MoveMetroidsTest, callsMoveOnMetroidsWhenTimeElapsedIsPastIntervalMultipliedByStep)
{
  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(metroid, move())
      .Times(55);
  moveMetroids(metroids, movementClock, variables, sounds);
}

TEST_F(MoveMetroidsTest, doesNotCallMoveOnMetroidsWhenTimeElapsedIsNotPastIntervalMultipliedByStep)
{
  sf::Time time(sf::milliseconds(6995));

  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(metroid, move())
      .Times(0);
  moveMetroids(metroids, movementClock, variables, sounds);
}

TEST_F(MoveMetroidsTest, adds1ToTheStepCounterWhenTimeElapsedIsPastIntervalMultipliedByStepAndMetroidsHaveNotJustMovedDown)
{
  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));
  ON_CALL(metroid, hasJustMovedDown())
      .WillByDefault(Return(false));

  moveMetroids(metroids, movementClock, variables, sounds);
  EXPECT_EQ(variables["step"], 8);
}

TEST_F(MoveMetroidsTest, callsRestartOnClockWhenTimeElapsedIsPastIntervalMultipliedByStepAndMetroidsHaveJustMovedDown)
{
  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));
  ON_CALL(metroid, hasJustMovedDown())
      .WillByDefault(Return(true));

  EXPECT_CALL(movementClock, restart())
      .Times(1);
  moveMetroids(metroids, movementClock, variables, sounds);
}

TEST_F(MoveMetroidsTest, decreasesIntervalBy35WhenTimeElapsedIsPastIntervalMultipliedByStepAndMetroidsHaveJustMovedDown)
{
  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));
  ON_CALL(metroid, hasJustMovedDown())
      .WillByDefault(Return(true));

  moveMetroids(metroids, movementClock, variables, sounds);
  EXPECT_EQ(variables["interval"], 965);
}

TEST_F(MoveMetroidsTest, setsStepCounterTo1WhenTimeElapsedIsPastIntervalMultipliedByStepAndMetroidsHaveJustMovedDown)
{
  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));
  ON_CALL(metroid, hasJustMovedDown())
      .WillByDefault(Return(true));

  moveMetroids(metroids, movementClock, variables, sounds);
  EXPECT_EQ(variables["step"], 1);
}

TEST_F(MoveMetroidsTest, playsSound0WhenTimeElapsedIsPastIntervalMultipliedByStepAndSoundCounterIs0)
{
  variables["soundCounter"] = {0};

  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(sound0, play())
      .Times(1);
  moveMetroids(metroids, movementClock, variables, sounds);
}

TEST_F(MoveMetroidsTest, playsSound1WhenTimeElapsedIsPastIntervalMultipliedByStepAndSoundCounterIs1)
{
  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(sound1, play())
      .Times(1);
  moveMetroids(metroids, movementClock, variables, sounds);
}

TEST_F(MoveMetroidsTest, playsSound2WhenTimeElapsedIsPastIntervalMultipliedByStepAndSoundCounterIs2)
{
  variables["soundCounter"] = {2};

  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(sound2, play())
      .Times(1);
  moveMetroids(metroids, movementClock, variables, sounds);
}

TEST_F(MoveMetroidsTest, playsSound3WhenTimeElapsedIsPastIntervalMultipliedByStepAndSoundCounterIs3)
{
  variables["soundCounter"] = {3};

  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(sound3, play())
      .Times(1);
  moveMetroids(metroids, movementClock, variables, sounds);
}

TEST_F(MoveMetroidsTest, increasesSoundCounterBy1WhenTimeElapsedIsPastInterval)
{
  variables["soundCounter"] = {26};

  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));

  moveMetroids(metroids, movementClock, variables, sounds);
  EXPECT_EQ(variables["soundCounter"], 27);
}
