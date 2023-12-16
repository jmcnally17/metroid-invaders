#include "../../../../include/game.hpp"
#include "../../../mockModels/mockMetroid.hpp"
#include "../../../mockModels/mockLaser.hpp"
#include "../../../mockModels/mockRidley.hpp"
#include "../../../mockModels/mockClock.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class LevelUpTest : public testing::Test
{
protected:
  std::unordered_map<std::string, int> variables {
    {"interval", 105},
    {"level", 5},
    {"soundCounter", 3},
    {"step", 15},
  };
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid {&metroid};
  std::array<std::array<IMetroid*, 11>, 5> metroids {{
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
  }};
  NiceMock<MockLaser> metroidLaser;
  MockLaser *pMetroidLaser {&metroidLaser};
  std::array<ILaser*, 3> metroidLasers {pMetroidLaser, pMetroidLaser, pMetroidLaser};
  NiceMock<MockRidley> ridley;
  NiceMock<MockClock> movementClock;
};

TEST_F(LevelUpTest, adds1ToTheLevelVariable)
{
  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
  EXPECT_EQ(variables["level"], 6);
}

TEST_F(LevelUpTest, resetsTheInterval)
{
  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
  EXPECT_EQ(variables["interval"], 665);
}

TEST_F(LevelUpTest, resetsTheStepCounter)
{
  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
  EXPECT_EQ(variables["step"], 1);
}

TEST_F(LevelUpTest, resetsTheSoundCounter)
{
  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
  EXPECT_EQ(variables["soundCounter"], 0);
}

TEST_F(LevelUpTest, callsResurrectOnEachMetroid)
{
  EXPECT_CALL(metroid, resurrect())
      .Times(55);
  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST_F(LevelUpTest, changesDirectionOnMetroidsIfTheyAreMovingLeft)
{
  ON_CALL(metroid, getDirection())
      .WillByDefault(Return(-1));

  EXPECT_CALL(metroid, changeDirection())
      .Times(55);
  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST_F(LevelUpTest, doesNotChangeDirectionOnMetroidsIfTheyAreMovingRight)
{
  ON_CALL(metroid, getDirection())
      .WillByDefault(Return(1));

  EXPECT_CALL(metroid, changeDirection())
      .Times(0);
  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST_F(LevelUpTest, setsNextLevelPositionOnMetroids)
{
  ON_CALL(metroid, getOriginalPosition())
      .WillByDefault(Return(sf::Vector2f(400, 960)));

  EXPECT_CALL(metroid, setPosition(sf::Vector2f(400, 1170)))
      .Times(55);
  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST_F(LevelUpTest, resetsTheMetroidLasers)
{
  EXPECT_CALL(metroidLaser, reset())
      .Times(3);
  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST_F(LevelUpTest, resetsRidley)
{
  EXPECT_CALL(ridley, reset())
      .Times(1);
  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST_F(LevelUpTest, stopsRidleyMovementSoundIfPlaying)
{
  EXPECT_CALL(ridley, stopMovementSoundIfPlaying())
      .Times(1);
  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST_F(LevelUpTest, restartsTheClock)
{
  EXPECT_CALL(movementClock, restart())
      .Times(1);
  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}
