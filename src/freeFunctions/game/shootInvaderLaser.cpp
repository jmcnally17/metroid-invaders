#include <vector>
#include "../../../include/models/iInvader.hpp"
#include "../../../include/models/iLaser.hpp"

void shootInvaderLaser(const std::vector<std::vector<IInvader *>> &invaders, const std::vector<ILaser *> &lasers)
{
  for (auto row : invaders)
  {
    for (auto invader : row)
    {
      if (invader->isAlive())
      {
        invader->shoot(lasers);
      }
    }
  }
}
