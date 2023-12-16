#include "../../../include/gameOver.hpp"
#include "../../mockModels/mockGunship.hpp"
#include "../../mockModels/mockLaser.hpp"
#include "../../mockModels/mockMetroid.hpp"
#include "../../mockModels/mockRidley.hpp"
#include "../../mockModels/mockBunker.hpp"

using ::testing::NiceMock;

class ResetObjectsTest : public testing::Test
{
protected:
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
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
  NiceMock<MockBunker> bunker;
  MockBunker *pBunker {&bunker};
  std::array<IBunker*, 4> bunkers {pBunker, pBunker, pBunker, pBunker};
};

TEST_F(ResetObjectsTest, resetsTheGunship)
{
  EXPECT_CALL(gunship, reset())
      .Times(1);
  resetObjects(gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers);
}

TEST_F(ResetObjectsTest, resetsTheGunshipLaser)
{
  EXPECT_CALL(gunshipLaser, reset())
      .Times(1);
  resetObjects(gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers);
}

TEST_F(ResetObjectsTest, resetsTheMetroids)
{
  EXPECT_CALL(metroid, reset())
      .Times(55);
  resetObjects(gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers);
}

TEST_F(ResetObjectsTest, resetsMetroidLasers)
{
  EXPECT_CALL(metroidLaser, reset())
      .Times(3);
  resetObjects(gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers);
}

TEST_F(ResetObjectsTest, resetsRidley)
{
  EXPECT_CALL(ridley, reset())
      .Times(1);
  resetObjects(gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers);
}

TEST_F(ResetObjectsTest, resetsTheBunkers)
{
  EXPECT_CALL(bunker, reset())
      .Times(4);
  resetObjects(gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers);
}
