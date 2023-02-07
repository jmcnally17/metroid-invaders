#include <vector>
#include "../../include/interfaces/collisionInterface.hpp"
#include "../../include/models/iLaser.hpp"
#include "../../include/models/iInvader.hpp"

void evaluateLaserInvaderCollision(const CollisionInterface &collision, const ILaser &laser, const std::vector<std::vector<IInvader *>> &invaders)
{
  for (auto vec : invaders)
  {
    for (auto invader : vec)
    {
      invader->die();
    }
  }
}
