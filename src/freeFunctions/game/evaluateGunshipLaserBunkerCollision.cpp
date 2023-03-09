#include <vector>
#include "../../../include/interfaces/collisionInterface.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iBunker.hpp"

void evaluateGunshipLaserBunkerCollision(const CollisionInterface &collision, ILaser &gunshipLaser, std::vector<IBunker *> &bunkers)
{
  for (auto bunker : bunkers)
  {
    if (bunker->getHealth() > 0 && collision.haveCollided(gunshipLaser, *bunker))
    {
      bunker->decreaseHealth();
      gunshipLaser.reset();
      return;
    }
  }
}
