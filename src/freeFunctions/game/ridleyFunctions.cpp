#include "../../../include/models/IRidley.hpp"

void monitorRidleyMovementSound(IRidley &ridley)
{
  ridley.stopMovementSoundIfAtSideOfWindow();
}

void spawnRidley(IRidley &ridley)
{
  ridley.spawn();
}
