#include <vector>
#include "../../../include/gameOver.hpp"
#include "../../mockModels/mockGunship.hpp"
#include "../../mockModels/mockLaser.hpp"
#include "../../mockModels/mockMetroid.hpp"
#include "../../mockModels/mockRidley.hpp"
#include "../../mockModels/mockBunker.hpp"

using ::testing::NiceMock;

TEST(resetObjects, resetsTheGunship)
{
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  std::vector<IBunker *> bunkers;

  EXPECT_CALL(gunship, reset())
      .Times(1);
  resetObjects(gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers);
}

TEST(resetObjects, resetsTheGunshipLaser)
{
  NiceMock<MockGunship> gunship;
  MockLaser gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  std::vector<IBunker *> bunkers;

  EXPECT_CALL(gunshipLaser, reset())
      .Times(1);
  resetObjects(gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers);
}

TEST(resetObjects, resetsTheMetroids)
{
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  MockMetroid metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(6);
    for (int j = 0; j < 6; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  std::vector<IBunker *> bunkers;

  EXPECT_CALL(metroid, reset())
      .Times(12);
  resetObjects(gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers);
}

TEST(resetObjects, resetsMetroidLasers)
{
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  MockLaser metroidLaser;
  MockLaser *pMetroidLaser = &metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = pMetroidLaser;
  }
  NiceMock<MockRidley> ridley;
  std::vector<IBunker *> bunkers;

  EXPECT_CALL(metroidLaser, reset())
      .Times(3);
  resetObjects(gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers);
}

TEST(resetObjects, resetsRidley)
{
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  MockRidley ridley;
  std::vector<IBunker *> bunkers;

  EXPECT_CALL(ridley, reset())
      .Times(1);
  resetObjects(gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers);
}

TEST(resetObjects, resetsTheBunkers)
{
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  MockBunker bunker;
  MockBunker *pBunker = &bunker;
  std::vector<IBunker *> bunkers(4);
  for (int i = 0; i < 4; i++)
  {
    bunkers[i] = pBunker;
  }

  EXPECT_CALL(bunker, reset())
      .Times(4);
  resetObjects(gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers);
}
