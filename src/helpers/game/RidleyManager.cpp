#include "../../../include/helpers/game/RidleyManager.hpp"

void RidleyManager::monitorRidleyMovementSound(IRidley &ridley) const
{
  ridley.stopMovementSoundIfAtSideOfWindow();
}

void RidleyManager::spawnRidley(IRidley &ridley) const
{
  ridley.spawn();
}

void RidleyManager::moveRidley(IRidley &ridley) const
{
  ridley.move();
}
