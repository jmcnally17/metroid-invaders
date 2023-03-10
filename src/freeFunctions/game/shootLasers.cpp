#include <vector>
#include "../../../include/models/iGunship.hpp"
#include "../../../include/models/iMetroid.hpp"
#include "../../../include/models/iLaser.hpp"

void fireGunshipLaser(IGunship &gunship)
{
  gunship.fire();
}

void shootMetroidLaser(const std::vector<std::vector<IMetroid *>> &metroids, const std::vector<ILaser *> &metroidLasers)
{
  for (auto row : metroids)
  {
    for (auto metroid : row)
    {
      if (metroid->isAlive())
      {
        metroid->shoot(metroidLasers);
      }
    }
  }
}
