#include <vector>
#include "../../../include/models/iInvader.hpp"

bool areInvadersDead(const std::vector<std::vector<IInvader *>> &invaders)
{
  for (auto row : invaders)
  {
    for (auto invader : row)
    {
      if (invader->isAlive())
      {
        return false;
      }
    }
  }
  return true;
}
