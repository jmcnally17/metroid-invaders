#include "../../../../include/Game.hpp"
#include "../../../mockModels/MockRidley.hpp"

TEST(monitorRidleyMovementSound, stopsRidleyMovementSoundIfAtSideOfWindow)
{
  MockRidley ridley;

  EXPECT_CALL(ridley, stopMovementSoundIfAtSideOfWindow())
      .Times(1);
  monitorRidleyMovementSound(ridley);
}
