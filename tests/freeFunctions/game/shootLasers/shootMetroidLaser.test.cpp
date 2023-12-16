#include "../../../../include/game.hpp"
#include "../../../mockModels/mockMetroid.hpp"
#include "../../../mockModels/mockLaser.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class ShootMetroidLaser : public testing::Test
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
  MockLaser metroidLaser;
  MockLaser *pMetroidLaser {&metroidLaser};
  std::array<ILaser*, 3> metroidLasers {pMetroidLaser, pMetroidLaser, pMetroidLaser};
};

TEST_F(ShootMetroidLaser, callsShootOnMetroidsIfTheyAreAlive)
{
  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(true));

  EXPECT_CALL(metroid, shoot)
      .Times(55);
  shootMetroidLaser(metroids, metroidLasers);
}

TEST_F(ShootMetroidLaser, doesNotCallShootOnMetroidsIfTheyAreDead)
{
  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(false));

  EXPECT_CALL(metroid, shoot)
      .Times(0);
  shootMetroidLaser(metroids, metroidLasers);
}
