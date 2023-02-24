#include <vector>
#include "../../../include/interfaces/collisionInterface.hpp"
#include "../../../include/models/iLaserCannon.hpp"
#include "../../../include/models/iLaser.hpp"

bool hasCannonBeenHit(const CollisionInterface &collision, const ILaserCannon &cannon, const std::vector<ILaser *> &invaderLasers)
{
  for (auto invaderLaser : invaderLasers)
  {
    ILaser &rLaser = *invaderLaser;
    if (collision.haveCollided(cannon, rLaser))
    {
      return true;
    }
  }
  return false;
}
