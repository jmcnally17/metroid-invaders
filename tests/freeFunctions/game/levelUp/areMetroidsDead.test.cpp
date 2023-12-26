#include "../../../../include/Game.hpp"
#include "../../../mockModels/MockMetroid.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class AreMetroidsDeadTest : public testing::Test
{
protected:
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
};

TEST_F(AreMetroidsDeadTest, returnsTrueIfAllMetroidsAreDead)
{
  ON_CALL(metroid1, isAlive)
      .WillByDefault(Return(false));

  EXPECT_TRUE(areMetroidsDead(metroids));
}

TEST_F(AreMetroidsDeadTest, returnsFalseIfAnyMetroidsAreAlive)
{
  metroids[3][7] = {pMetroid2};

  ON_CALL(metroid1, isAlive)
      .WillByDefault(Return(false));
  ON_CALL(metroid2, isAlive)
      .WillByDefault(Return(true));

  EXPECT_FALSE(areMetroidsDead(metroids));
}
