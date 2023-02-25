#include "../../../include/game.hpp"
#include "../../mockModels/mockMetroid.hpp"
#include "../../mockModels/mockLaser.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(shootMetroidLaser, callsShootOnMetroidsIfTheyAreAlive)
{
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(3);
    for (int j = 0; j < 3; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  MockLaser *laser;
  std::vector<ILaser *> lasers(3);
  for (int i = 0; i < 3; i++)
  {
    lasers[i] = laser;
  }

  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(true));

  EXPECT_CALL(metroid, shoot)
      .Times(6);
  shootMetroidLaser(metroids, lasers);
}

TEST(shootMetroidLaser, doesNotCallShootOnMetroidsIfTheyAreDead)
{
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(3);
    for (int j = 0; j < 3; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  MockLaser *laser;
  std::vector<ILaser *> lasers(3);
  for (int i = 0; i < 3; i++)
  {
    lasers[i] = laser;
  }

  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(false));

  EXPECT_CALL(metroid, shoot)
      .Times(0);
  shootMetroidLaser(metroids, lasers);
}
