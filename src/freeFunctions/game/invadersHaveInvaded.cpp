#include <vector>
#include "../../../include/models/iInvader.hpp"

bool invadersHaveInvaded(const std::vector<std::vector<IInvader *>> &invaders)
{
  for (auto vec : invaders)
  {
    for (auto invader : vec)
    {
      if (invader->isAlive() && invader->getPosition().y >= 1128)
      {
        return true;
      }
    }
  }
  return false;
}
