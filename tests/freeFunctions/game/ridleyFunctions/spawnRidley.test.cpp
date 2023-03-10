#include "../../../../include/game.hpp"
#include "../../../mockModels/mockRidley.hpp"

TEST(spawnRidley, callsSpawnOnRidley)
{
  MockRidley ridley;

  EXPECT_CALL(ridley, spawn)
      .Times(1);
  spawnRidley(ridley);
}
