#include "../../../include/models/iRidley.hpp"

void monitorRidleyMovementSound(IRidley &ridley)
{
  ridley.stopMovementSoundIfAtSideOfWindow();
}
