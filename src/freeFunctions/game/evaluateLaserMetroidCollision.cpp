#include <vector>
#include "../../../include/interfaces/collisionInterface.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iMetroid.hpp"
#include "../../../include/wrappers/iText.hpp"

void evaluateLaserMetroidCollision(const CollisionInterface &collision, ILaser &laser, const std::vector<std::vector<IMetroid *>> &metroids, int &score, IText &scoreText)
{
  for (auto vec : metroids)
  {
    for (auto metroid : vec)
    {
      if (metroid->isAlive() && collision.haveCollided(laser, *metroid))
      {
        metroid->die();
        score += metroid->getPoints();
        scoreText.setString("Score: " + std::to_string(score));
        laser.playMetroidDeath();
        laser.reset();
        return;
      }
    }
  }
}
