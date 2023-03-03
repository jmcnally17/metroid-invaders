#include <vector>
#include "../../../include/interfaces/collisionInterface.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iMetroid.hpp"
#include "../../../include/wrappers/iText.hpp"

void evaluateGunshipLaserMetroidCollision(const CollisionInterface &collision, ILaser &gunshipLaser, const std::vector<std::vector<IMetroid *>> &metroids, int &score, IText &scoreText)
{
  for (auto vec : metroids)
  {
    for (auto metroid : vec)
    {
      if (metroid->isAlive() && collision.haveCollided(gunshipLaser, *metroid))
      {
        metroid->die();
        score += metroid->getPoints();
        scoreText.setString("Score: " + std::to_string(score));
        gunshipLaser.playMetroidDeath();
        gunshipLaser.reset();
        return;
      }
    }
  }
}
