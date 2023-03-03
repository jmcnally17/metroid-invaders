#include <vector>
#include "../../../include/interfaces/collisionInterface.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iMetroid.hpp"
#include "../../../include/wrappers/iText.hpp"

void evaluateCannonLaserMetroidCollision(const CollisionInterface &collision, ILaser &cannonLaser, const std::vector<std::vector<IMetroid *>> &metroids, int &score, IText &scoreText)
{
  for (auto vec : metroids)
  {
    for (auto metroid : vec)
    {
      if (metroid->isAlive() && collision.haveCollided(cannonLaser, *metroid))
      {
        metroid->die();
        score += metroid->getPoints();
        scoreText.setString("Score: " + std::to_string(score));
        cannonLaser.playMetroidDeath();
        cannonLaser.reset();
        return;
      }
    }
  }
}
