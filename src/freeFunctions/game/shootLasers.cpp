#include "../../../include/models/iGunship.hpp"
#include "../../../include/models/iMetroid.hpp"
#include "../../../include/models/iLaser.hpp"

void fireGunshipLaser(IGunship &gunship)
{
  gunship.fire();
}

void shootMetroidLaser(const std::array<std::array<IMetroid*, 11>, 5> &metroids, const std::array<ILaser*, 3> &metroidLasers)
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
