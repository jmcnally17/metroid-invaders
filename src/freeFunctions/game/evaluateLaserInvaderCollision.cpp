#include <vector>
#include "../../../include/interfaces/collisionInterface.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iInvader.hpp"

void evaluateLaserInvaderCollision(const CollisionInterface &collision, ILaser &laser, const std::vector<std::vector<IInvader *>> &invaders, int &score)
{
  for (auto vec : invaders)
  {
    for (auto invader : vec)
    {
      IInvader &rInvader = *invader;
      if (rInvader.isAlive() && collision.haveCollided(laser, rInvader))
      {
        invader->die();
        score += invader->getPoints();
        laser.playInvaderDeath();
        laser.reset();
        return;
      }
    }
  }
}
