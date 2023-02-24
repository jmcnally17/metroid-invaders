#include <vector>
#include "../../../include/models/iMetroid.hpp"

bool areMetroidsDead(const std::vector<std::vector<IMetroid *>> &metroids)
{
  for (auto row : metroids)
  {
    for (auto metroid : row)
    {
      if (metroid->isAlive())
      {
        return false;
      }
    }
  }
  return true;
}
