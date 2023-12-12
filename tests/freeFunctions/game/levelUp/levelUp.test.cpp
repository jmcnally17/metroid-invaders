#include "../../../../include/game.hpp"
#include "../../../mockModels/mockMetroid.hpp"
#include "../../../mockModels/mockLaser.hpp"
#include "../../../mockModels/mockRidley.hpp"
#include "../../../mockModels/mockClock.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(levelUp, adds1ToTheLevelVariable)
{
  std::unordered_map<std::string, int> variables = {
    {"interval", 105},
    {"level", 5},
    {"soundCounter", 3},
    {"step", 15},
  };
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  NiceMock<MockClock> movementClock;

  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
  EXPECT_EQ(variables["level"], 6);
}

TEST(levelUp, resetsTheInterval)
{
  std::unordered_map<std::string, int> variables = {
    {"interval", 105},
    {"level", 5},
    {"soundCounter", 3},
    {"step", 15},
  };
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  NiceMock<MockClock> movementClock;

  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
  EXPECT_EQ(variables["interval"], 665);
}

TEST(levelUp, resetsTheStepCounter)
{
  std::unordered_map<std::string, int> variables = {
    {"interval", 105},
    {"level", 5},
    {"soundCounter", 3},
    {"step", 15},
  };
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  NiceMock<MockClock> movementClock;

  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
  EXPECT_EQ(variables["step"], 1);
}

TEST(levelUp, resetsTheSoundCounter)
{
  std::unordered_map<std::string, int> variables = {
    {"interval", 105},
    {"level", 5},
    {"soundCounter", 3},
    {"step", 15},
  };
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  NiceMock<MockClock> movementClock;

  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
  EXPECT_EQ(variables["soundCounter"], 0);
}

TEST(levelUp, callsResurrectOnEachMetroid)
{
  std::unordered_map<std::string, int> variables = {
    {"interval", 105},
    {"level", 5},
    {"soundCounter", 3},
    {"step", 15},
  };
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(4);
    for (int j = 0; j < 4; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  NiceMock<MockClock> movementClock;

  EXPECT_CALL(metroid, resurrect())
      .Times(8);
  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST(levelUp, changesDirectionOnMetroidsIfTheyAreMovingLeft)
{
  std::unordered_map<std::string, int> variables = {
    {"interval", 105},
    {"level", 5},
    {"soundCounter", 3},
    {"step", 15},
  };
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(4);
    for (int j = 0; j < 4; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  NiceMock<MockClock> movementClock;

  ON_CALL(metroid, getDirection())
      .WillByDefault(Return(-1));

  EXPECT_CALL(metroid, changeDirection())
      .Times(8);
  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST(levelUp, doesNotChangeDirectionOnMetroidsIfTheyAreMovingRight)
{
  std::unordered_map<std::string, int> variables = {
    {"interval", 105},
    {"level", 5},
    {"soundCounter", 3},
    {"step", 15},
  };
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(4);
    for (int j = 0; j < 4; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  NiceMock<MockClock> movementClock;

  ON_CALL(metroid, getDirection())
      .WillByDefault(Return(1));

  EXPECT_CALL(metroid, changeDirection())
      .Times(0);
  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST(levelUp, setsNextLevelPositionOnMetroids)
{
  std::unordered_map<std::string, int> variables = {
    {"interval", 105},
    {"level", 5},
    {"soundCounter", 3},
    {"step", 15},
  };
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(4);
    for (int j = 0; j < 4; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  NiceMock<MockClock> movementClock;

  ON_CALL(metroid, getOriginalPosition())
      .WillByDefault(Return(sf::Vector2f(400, 960)));

  EXPECT_CALL(metroid, setPosition(sf::Vector2f(400, 1170)))
      .Times(8);
  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST(levelUp, resetsTheMetroidLasers)
{
  std::unordered_map<std::string, int> variables = {
    {"interval", 105},
    {"level", 5},
    {"soundCounter", 3},
    {"step", 15},
  };
  std::vector<std::vector<IMetroid *>> metroids;
  MockLaser metroidLaser;
  MockLaser *pMetroidLaser = &metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = pMetroidLaser;
  }
  NiceMock<MockRidley> ridley;
  NiceMock<MockClock> movementClock;

  EXPECT_CALL(metroidLaser, reset())
      .Times(3);
  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST(levelUp, resetsRidley)
{
  std::unordered_map<std::string, int> variables = {
    {"interval", 105},
    {"level", 5},
    {"soundCounter", 3},
    {"step", 15},
  };
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  NiceMock<MockClock> movementClock;

  EXPECT_CALL(ridley, reset())
      .Times(1);
  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST(levelUp, stopsRidleyMovementSoundIfPlaying)
{
  std::unordered_map<std::string, int> variables = {
    {"interval", 105},
    {"level", 5},
    {"soundCounter", 3},
    {"step", 15},
  };
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  NiceMock<MockClock> movementClock;

  EXPECT_CALL(ridley, stopMovementSoundIfPlaying())
      .Times(1);
  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST(levelUp, restartsTheClock)
{
  std::unordered_map<std::string, int> variables = {
    {"interval", 105},
    {"level", 5},
    {"soundCounter", 3},
    {"step", 15},
  };
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  MockClock movementClock;

  EXPECT_CALL(movementClock, restart())
      .Times(1);
  levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}
