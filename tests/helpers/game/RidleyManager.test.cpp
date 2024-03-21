#include "../../../include/helpers/game/RidleyManager.hpp"
#include "../../mockModels/MockRidley.hpp"

class RidleyManagerTest : public testing::Test
{
protected:
  RidleyManager ridleyManager;
  MockRidley ridley;
};

TEST_F(RidleyManagerTest, monitorRidleyMovementSoundStopsRidleyMovementSoundIfAtSideOfWindow)
{
  EXPECT_CALL(ridley, stopMovementSoundIfAtSideOfWindow())
      .Times(1);
  ridleyManager.monitorRidleyMovementSound(ridley);
}

TEST_F(RidleyManagerTest, spawnRidleyCallsSpawnOnRidley)
{
  EXPECT_CALL(ridley, spawn)
      .Times(1);
  ridleyManager.spawnRidley(ridley);
}

TEST_F(RidleyManagerTest, moveRidleyCallsMoveOnRidley)
{
  EXPECT_CALL(ridley, move())
      .Times(1);
  ridleyManager.moveRidley(ridley);
}
