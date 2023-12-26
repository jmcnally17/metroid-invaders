#include "../../../include/models/IGunship.hpp"
#include "../../../include/models/IMetroid.hpp"
#include "../../../include/models/IMetroidLaser.hpp"

void fireGunshipLaser(IGunship &gunship)
{
  gunship.fire();
}

void shootMetroidLaser(const std::array<std::array<IMetroid*, 11>, 5> &metroids, const std::array<IMetroidLaser*, 3> &metroidLasers)
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
