#include "../../../../include/Game.hpp"
#include "../../../mockModels/MockMetroid.hpp"
#include "../../../mockModels/MockMetroidLaser.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class ShootMetroidLaserTest : public testing::Test
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
  MockMetroidLaser metroidLaser;
  MockMetroidLaser *pMetroidLaser {&metroidLaser};
  std::array<IMetroidLaser*, 3> metroidLasers {pMetroidLaser, pMetroidLaser, pMetroidLaser};
};

TEST_F(ShootMetroidLaserTest, callsShootOnMetroidsIfTheyAreAlive)
{
  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(true));

  EXPECT_CALL(metroid, shoot)
      .Times(55);
  shootMetroidLaser(metroids, metroidLasers);
}

TEST_F(ShootMetroidLaserTest, doesNotCallShootOnMetroidsIfTheyAreDead)
{
  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(false));

  EXPECT_CALL(metroid, shoot)
      .Times(0);
  shootMetroidLaser(metroids, metroidLasers);
}
