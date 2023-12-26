#include "../../../../include/Game.hpp"
#include "../../../mockModels/MockRidley.hpp"

TEST(spawnRidley, callsSpawnOnRidley)
{
  MockRidley ridley;

  EXPECT_CALL(ridley, spawn)
      .Times(1);
  spawnRidley(ridley);
}
