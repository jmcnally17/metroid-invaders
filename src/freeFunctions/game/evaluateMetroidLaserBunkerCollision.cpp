#include <vector>
#include "../../../include/interfaces/collisionInterface.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iBunker.hpp"

void evaluateMetroidLaserBunkerCollision(const CollisionInterface &collision, const std::vector<ILaser *> &metroidLasers, std::vector<IBunker *> &bunkers)
{
  for (auto metroidLaser : metroidLasers)
  {
    int count = 0;
    while (count < 4)
    {
      IBunker *bunker = bunkers[count];
      if (bunker->getHealth() > 0 && collision.haveCollided(*metroidLaser, *bunker))
      {
        bunker->decreaseHealth();
        metroidLaser->reset();
        count = 4;
      }
      else
      {
        count++;
      }
    }
  }
}
