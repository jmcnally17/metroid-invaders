#include "../../../include/game.hpp"
#include "../../mockModels/mockMetroid.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(areMetroidsDead, returnsTrueIfAllMetroidsAreDead)
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

  ON_CALL(metroid, isAlive)
      .WillByDefault(Return(false));

  EXPECT_TRUE(areMetroidsDead(metroids));
}

TEST(areMetroidsDead, returnsFalseIfAnyMetroidsAreAlive)
{
  NiceMock<MockMetroid> metroid1;
  MockMetroid *pMetroid1 = &metroid1;
  NiceMock<MockMetroid> metroid2;
  MockMetroid *pMetroid2 = &metroid2;
  std::vector<std::vector<IMetroid *>> metroids(2);
  std::vector<IMetroid *> metroidRow1(2);
  metroidRow1[0] = pMetroid1;
  metroidRow1[1] = pMetroid1;
  std::vector<IMetroid *> metroidRow2(2);
  metroidRow2[0] = pMetroid2;
  metroidRow2[1] = pMetroid1;
  metroids[0] = metroidRow1;
  metroids[1] = metroidRow2;

  ON_CALL(metroid1, isAlive)
      .WillByDefault(Return(false));
  ON_CALL(metroid1, isAlive)
      .WillByDefault(Return(true));

  EXPECT_FALSE(areMetroidsDead(metroids));
}
