#include <vector>
#include "../../../include/interfaces/collisionInterface.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iBunker.hpp"

void evaluateGunshipLaserBunkerCollision(const CollisionInterface &collision, ILaser &gunshipLaser, std::vector<IBunker *> &bunkers)
{
  for (auto bunker : bunkers)
  {
    bunker->decreaseHealth();
    return;
  }
}
