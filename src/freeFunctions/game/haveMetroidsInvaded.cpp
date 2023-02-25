#include <vector>
#include "../../../include/models/iMetroid.hpp"

bool haveMetroidsInvaded(const std::vector<std::vector<IMetroid *>> &metroids)
{
  for (auto vec : metroids)
  {
    for (auto metroid : vec)
    {
      if (metroid->isAlive() && metroid->getPosition().y >= 1128)
      {
        return true;
      }
    }
  }
  return false;
}
