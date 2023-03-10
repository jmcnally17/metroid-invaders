#include "../../../../include/game.hpp"
#include "../../../mockModels/mockRidley.hpp"

TEST(monitorRidleyMovementSound, stopsRidleyMovementSoundIfAtSideOfWindow)
{
  MockRidley ridley;

  EXPECT_CALL(ridley, stopMovementSoundIfAtSideOfWindow())
      .Times(1);
  monitorRidleyMovementSound(ridley);
}
