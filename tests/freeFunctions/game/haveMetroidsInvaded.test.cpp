#include <vector>
#include "../../../include/game.hpp"
#include "../../mockModels/mockMetroid.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(haveMetroidsInvaded, returnsTrueIfAnMetroidHasReachedTheBottomAndIsAlive)
{
  NiceMock<MockMetroid> metroid1;
  MockMetroid *pMetroid1 = &metroid1;
  NiceMock<MockMetroid> metroid2;
  MockMetroid *pMetroid2 = &metroid2;
  std::vector<std::vector<IMetroid *>> metroids(2);

  std::vector<IMetroid *> metroidRow1(2);
  metroidRow1[0] = pMetroid2;
  metroidRow1[1] = pMetroid2;
  metroids[0] = metroidRow1;
  std::vector<IMetroid *> metroidRow2(2);
  metroidRow2[0] = pMetroid1;
  metroidRow2[1] = pMetroid2;
  metroids[1] = metroidRow2;

  ON_CALL(metroid1, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 1128)));
  ON_CALL(metroid2, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 900)));
  ON_CALL(metroid1, isAlive)
      .WillByDefault(Return(true));
  ON_CALL(metroid2, isAlive)
      .WillByDefault(Return(false));

  EXPECT_TRUE(haveMetroidsInvaded(metroids));
}

TEST(haveMetroidsInvaded, returnsfalseIfMetroidsHaveNotReachedTheBottomAndAreAlive)
{
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);

  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(2);
    for (int j = 0; j < 2; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }

  ON_CALL(metroid, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 900)));
  ON_CALL(metroid, isAlive)
      .WillByDefault(Return(true));

  EXPECT_FALSE(haveMetroidsInvaded(metroids));
}

TEST(haveMetroidsInvaded, returnsfalseIfMetroidsHaveReachedTheBottomButAreDead)
{
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);

  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(2);
    for (int j = 0; j < 2; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }

  ON_CALL(metroid, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 1128)));
  ON_CALL(metroid, isAlive)
      .WillByDefault(Return(false));

  EXPECT_FALSE(haveMetroidsInvaded(metroids));
}
