#include "../../../../include/game.hpp"
#include "../../../mockModels/mockMetroid.hpp"
#include "../../../mockModels/mockLaser.hpp"
#include "../../../mockModels/mockRidley.hpp"
#include "../../../mockModels/mockClock.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(levelUp, adds1ToTheLevelVariable)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  NiceMock<MockClock> clock;

  levelUp(level, interval, step, soundCounter, metroids, metroidLasers, ridley, clock);
  EXPECT_EQ(level, 6);
}

TEST(levelUp, resetsTheInterval)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  NiceMock<MockClock> clock;

  levelUp(level, interval, step, soundCounter, metroids, metroidLasers, ridley, clock);
  EXPECT_EQ(interval, 665);
}

TEST(levelUp, resetsTheStepCounter)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  NiceMock<MockClock> clock;

  levelUp(level, interval, step, soundCounter, metroids, metroidLasers, ridley, clock);
  EXPECT_EQ(step, 1);
}

TEST(levelUp, resetsTheSoundCounter)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  NiceMock<MockClock> clock;

  levelUp(level, interval, step, soundCounter, metroids, metroidLasers, ridley, clock);
  EXPECT_EQ(soundCounter, 0);
}

TEST(levelUp, callsResurrectOnEachMetroid)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
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
  NiceMock<MockClock> clock;

  EXPECT_CALL(metroid, resurrect())
      .Times(8);
  levelUp(level, interval, step, soundCounter, metroids, metroidLasers, ridley, clock);
}

TEST(levelUp, changesDirectionOnMetroidsIfTheyAreMovingLeft)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
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
  NiceMock<MockClock> clock;

  ON_CALL(metroid, getDirection())
      .WillByDefault(Return(-1));

  EXPECT_CALL(metroid, changeDirection())
      .Times(8);
  levelUp(level, interval, step, soundCounter, metroids, metroidLasers, ridley, clock);
}

TEST(levelUp, doesNotChangeDirectionOnMetroidsIfTheyAreMovingRight)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
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
  NiceMock<MockClock> clock;

  ON_CALL(metroid, getDirection())
      .WillByDefault(Return(1));

  EXPECT_CALL(metroid, changeDirection())
      .Times(0);
  levelUp(level, interval, step, soundCounter, metroids, metroidLasers, ridley, clock);
}

TEST(levelUp, setsNextLevelPositionOnMetroids)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
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
  NiceMock<MockClock> clock;

  ON_CALL(metroid, getOriginalPosition())
      .WillByDefault(Return(sf::Vector2f(400, 960)));

  EXPECT_CALL(metroid, setPosition(sf::Vector2f(400, 1170)))
      .Times(8);
  levelUp(level, interval, step, soundCounter, metroids, metroidLasers, ridley, clock);
}

TEST(levelUp, resetsTheMetroidLasers)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
  std::vector<std::vector<IMetroid *>> metroids;
  MockLaser metroidLaser;
  MockLaser *pMetroidLaser = &metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = pMetroidLaser;
  }
  NiceMock<MockRidley> ridley;
  NiceMock<MockClock> clock;

  EXPECT_CALL(metroidLaser, reset())
      .Times(3);
  levelUp(level, interval, step, soundCounter, metroids, metroidLasers, ridley, clock);
}

TEST(levelUp, resetsRidley)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  NiceMock<MockClock> clock;

  EXPECT_CALL(ridley, reset())
      .Times(1);
  levelUp(level, interval, step, soundCounter, metroids, metroidLasers, ridley, clock);
}

TEST(levelUp, stopsRidleyMovementSoundIfPlaying)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  NiceMock<MockClock> clock;

  EXPECT_CALL(ridley, stopMovementSoundIfPlaying())
      .Times(1);
  levelUp(level, interval, step, soundCounter, metroids, metroidLasers, ridley, clock);
}

TEST(levelUp, restartsTheClock)
{
  int level = 5;
  int interval = 105;
  int step = 15;
  int soundCounter = 3;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  MockClock clock;

  EXPECT_CALL(clock, restart())
      .Times(1);
  levelUp(level, interval, step, soundCounter, metroids, metroidLasers, ridley, clock);
}
