#include <vector>
#include "../../../include/models/iMetroid.hpp"
#include "../../../include/models/iLaser.hpp"

void shootMetroidLaser(const std::vector<std::vector<IMetroid *>> &metroids, const std::vector<ILaser *> &lasers)
{
  for (auto row : metroids)
  {
    for (auto metroid : row)
    {
      if (metroid->isAlive())
      {
        metroid->shoot(lasers);
      }
    }
  }
}
