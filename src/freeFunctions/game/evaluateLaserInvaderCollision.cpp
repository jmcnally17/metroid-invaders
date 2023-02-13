#include <vector>
#include "../../../include/interfaces/collisionInterface.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iInvader.hpp"
#include "../../../include/wrappers/iText.hpp"

void evaluateLaserInvaderCollision(const CollisionInterface &collision, ILaser &laser, const std::vector<std::vector<IInvader *>> &invaders, int &score, IText &scoreText)
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
        scoreText.setString("Score: " + std::to_string(score));
        laser.playInvaderDeath();
        laser.reset();
        return;
      }
    }
  }
}
