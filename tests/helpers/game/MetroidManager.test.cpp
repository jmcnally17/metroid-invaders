#include "../../../include/Constants.hpp"
#include "../../../include/helpers/game/MetroidManager.hpp"
#include "../../mockModels/MockClock.hpp"
#include "../../mockModels/MockMetroid.hpp"
#include "../../mockModels/MockMetroidLaser.hpp"
#include "../../mockModels/MockSound.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class MetroidManagerTest : public testing::Test
{
protected:
  MetroidManager metroidManager;
  NiceMock<MockMetroid> metroid1;
  MockMetroid *pMetroid1 {&metroid1};
  NiceMock<MockMetroid> metroid2;
  MockMetroid *pMetroid2 {&metroid2};
  std::array<std::array<IMetroid*, 11>, 5> metroids {{
    {{pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1}},
    {{pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1}},
    {{pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1}},
    {{pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1}},
    {{pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1, pMetroid1}},
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
  MockMetroidLaser metroidLaser;
  MockMetroidLaser *pMetroidLaser {&metroidLaser};
  std::array<IMetroidLaser*, 3> metroidLasers {pMetroidLaser, pMetroidLaser, pMetroidLaser};
};

TEST_F(MetroidManagerTest, areMetroidsDeadReturnsTrueIfAllMetroidsAreDead)
{
  ON_CALL(metroid1, isAlive)
      .WillByDefault(Return(false));

  EXPECT_TRUE(metroidManager.areMetroidsDead(metroids));
}

TEST_F(MetroidManagerTest, areMetroidsDeadReturnsFalseIfAnyMetroidsAreAlive)
{
  metroids[3][7] = {pMetroid2};

  ON_CALL(metroid1, isAlive)
      .WillByDefault(Return(false));
  ON_CALL(metroid2, isAlive)
      .WillByDefault(Return(true));

  EXPECT_FALSE(metroidManager.areMetroidsDead(metroids));
}

TEST_F(MetroidManagerTest, haveMetroidsInvadedReturnsTrueIfAMetroidHasReachedTheBottomAndIsAlive)
{
  metroids[3][7] = {pMetroid2};
  
  ON_CALL(metroid1, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 10 * Constants::LENGTH_SCALE)));
  ON_CALL(metroid2, getPosition)
    .WillByDefault(Return(sf::Vector2f(500, 70.5 * Constants::LENGTH_SCALE)));
  ON_CALL(metroid1, isAlive)
      .WillByDefault(Return(false));
  ON_CALL(metroid2, isAlive)
      .WillByDefault(Return(true));

  EXPECT_TRUE(metroidManager.haveMetroidsInvaded(metroids));
}

TEST_F(MetroidManagerTest, haveMetroidsInvadedReturnsfalseIfMetroidsHaveNotReachedTheBottomAndAreAlive)
{
  ON_CALL(metroid1, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 10 * Constants::LENGTH_SCALE)));
  ON_CALL(metroid1, isAlive)
      .WillByDefault(Return(true));

  EXPECT_FALSE(metroidManager.haveMetroidsInvaded(metroids));
}

TEST_F(MetroidManagerTest, haveMetroidsInvadedReturnsfalseIfMetroidsHaveReachedTheBottomButAreDead)
{
  ON_CALL(metroid1, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 70.5 * Constants::LENGTH_SCALE)));
  ON_CALL(metroid1, isAlive)
      .WillByDefault(Return(false));

  EXPECT_FALSE(metroidManager.haveMetroidsInvaded(metroids));
}

TEST_F(MetroidManagerTest, moveMetroidsCallsMoveOnMetroidsWhenTimeElapsedIsPastIntervalMultipliedByStep)
{
  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(metroid1, move())
      .Times(55);
  metroidManager.moveMetroids(metroids, movementClock, variables, sounds);
}

TEST_F(MetroidManagerTest, moveMetroidsDoesNotCallMoveOnMetroidsWhenTimeElapsedIsNotPastIntervalMultipliedByStep)
{
  sf::Time time(sf::milliseconds(6995));

  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(metroid1, move)
      .Times(0);
  metroidManager.moveMetroids(metroids, movementClock, variables, sounds);
}

TEST_F(MetroidManagerTest, moveMetroidsAdds1ToTheStepCounterWhenTimeElapsedIsPastIntervalMultipliedByStepAndMetroidsHaveNotJustMovedDown)
{
  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));
  ON_CALL(metroid1, hasJustMovedDown())
      .WillByDefault(Return(false));

  metroidManager.moveMetroids(metroids, movementClock, variables, sounds);
  EXPECT_EQ(variables["step"], 8);
}

TEST_F(MetroidManagerTest, moveMetroidsCallsRestartOnClockWhenTimeElapsedIsPastIntervalMultipliedByStepAndMetroidsHaveJustMovedDown)
{
  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));
  ON_CALL(metroid1, hasJustMovedDown())
      .WillByDefault(Return(true));

  EXPECT_CALL(movementClock, restart())
      .Times(1);
  metroidManager.moveMetroids(metroids, movementClock, variables, sounds);
}

TEST_F(MetroidManagerTest, moveMetroidsDecreasesIntervalBy35WhenTimeElapsedIsPastIntervalMultipliedByStepAndMetroidsHaveJustMovedDown)
{
  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));
  ON_CALL(metroid1, hasJustMovedDown())
      .WillByDefault(Return(true));

  metroidManager.moveMetroids(metroids, movementClock, variables, sounds);
  EXPECT_EQ(variables["interval"], 965);
}

TEST_F(MetroidManagerTest, moveMetroidsSetsStepCounterTo1WhenTimeElapsedIsPastIntervalMultipliedByStepAndMetroidsHaveJustMovedDown)
{
  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));
  ON_CALL(metroid1, hasJustMovedDown())
      .WillByDefault(Return(true));

  metroidManager.moveMetroids(metroids, movementClock, variables, sounds);
  EXPECT_EQ(variables["step"], 1);
}

TEST_F(MetroidManagerTest, moveMetroidsPlaysSound0WhenTimeElapsedIsPastIntervalMultipliedByStepAndSoundCounterIs0)
{
  variables["soundCounter"] = {0};

  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(sound0, play())
      .Times(1);
  metroidManager.moveMetroids(metroids, movementClock, variables, sounds);
}

TEST_F(MetroidManagerTest, moveMetroidsPlaysSound1WhenTimeElapsedIsPastIntervalMultipliedByStepAndSoundCounterIs1)
{
  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(sound1, play())
      .Times(1);
  metroidManager.moveMetroids(metroids, movementClock, variables, sounds);
}

TEST_F(MetroidManagerTest, moveMetroidsPlaysSound2WhenTimeElapsedIsPastIntervalMultipliedByStepAndSoundCounterIs2)
{
  variables["soundCounter"] = {2};

  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(sound2, play())
      .Times(1);
  metroidManager.moveMetroids(metroids, movementClock, variables, sounds);
}

TEST_F(MetroidManagerTest, moveMetroidsPlaysSound3WhenTimeElapsedIsPastIntervalMultipliedByStepAndSoundCounterIs3)
{
  variables["soundCounter"] = {3};

  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));

  EXPECT_CALL(sound3, play())
      .Times(1);
  metroidManager.moveMetroids(metroids, movementClock, variables, sounds);
}

TEST_F(MetroidManagerTest, moveMetroidsIncreasesSoundCounterBy1WhenTimeElapsedIsPastInterval)
{
  variables["soundCounter"] = {26};

  ON_CALL(movementClock, getElapsedTime())
      .WillByDefault(Return(time));

  metroidManager.moveMetroids(metroids, movementClock, variables, sounds);
  EXPECT_EQ(variables["soundCounter"], 27);
}

TEST_F(MetroidManagerTest, moveMetroidLasersCallsMoveOnMetroidLasers)
{
  EXPECT_CALL(metroidLaser, move())
      .Times(3);
  metroidManager.moveMetroidLasers(metroidLasers);
}

TEST_F(MetroidManagerTest, shootMetroidLaserCallsShootOnMetroidsIfTheyAreAlive)
{
  ON_CALL(metroid1, isAlive())
      .WillByDefault(Return(true));

  EXPECT_CALL(metroid1, shoot)
      .Times(55);
  metroidManager.shootMetroidLaser(metroids, metroidLasers);
}

TEST_F(MetroidManagerTest, shootMetroidLaserDoesNotCallShootOnMetroidsIfTheyAreDead)
{
  ON_CALL(metroid1, isAlive())
      .WillByDefault(Return(false));

  EXPECT_CALL(metroid1, shoot)
      .Times(0);
  metroidManager.shootMetroidLaser(metroids, metroidLasers);
}
