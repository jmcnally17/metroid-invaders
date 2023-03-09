#include <vector>
#include "../../../include/interfaces/collisionInterface.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iBunker.hpp"

void evaluateMetroidLaserBunkerCollision(const CollisionInterface &collision, const std::vector<ILaser *> &metroidLasers, std::vector<IBunker *> &bunkers)
{
  for (auto metroidLaser : metroidLasers)
  {
    for (auto bunker : bunkers)
    {
      bunker->decreaseHealth();
    }
  }
}
