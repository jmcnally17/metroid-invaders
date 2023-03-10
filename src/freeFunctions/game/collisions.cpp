#include <vector>
#include "../../../include/interfaces/collisionInterface.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iMetroid.hpp"
#include "../../../include/models/iRidley.hpp"
#include "../../../include/models/iBunker.hpp"
#include "../../../include/models/iGunship.hpp"
#include "../../../include/wrappers/iText.hpp"

void evaluateGunshipLaserMetroidCollision(const CollisionInterface &collision,
                                          ILaser &gunshipLaser,
                                          const std::vector<std::vector<IMetroid *>> &metroids,
                                          int &score,
                                          IText &scoreText)
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

void evaluateGunshipLaserRidleyCollision(const CollisionInterface &collision, ILaser &gunshipLaser, IRidley &ridley, int &score, IText &scoreText)
{
  if (collision.haveCollided(gunshipLaser, ridley))
  {
    ridley.die();
    score += ridley.getPoints();
    scoreText.setString("Score: " + std::to_string(score));
    gunshipLaser.reset();
  }
}

void evaluateGunshipLaserBunkerCollision(const CollisionInterface &collision, ILaser &gunshipLaser, std::vector<IBunker *> &bunkers)
{
  for (auto bunker : bunkers)
  {
    if (bunker->getHealth() > 0 && collision.haveCollided(gunshipLaser, *bunker))
    {
      bunker->decreaseHealth();
      gunshipLaser.reset();
      return;
    }
  }
}

void evaluateMetroidLaserBunkerCollision(const CollisionInterface &collision, const std::vector<ILaser *> &metroidLasers, std::vector<IBunker *> &bunkers)
{
  for (auto metroidLaser : metroidLasers)
  {
    int count = 0;
    while (count < 4)
    {
      IBunker *bunker = bunkers[count];
      if (bunker->getHealth() > 0 && collision.haveCollided(*metroidLaser, *bunker))
      {
        bunker->decreaseHealth();
        metroidLaser->reset();
        count = 4;
      }
      else
      {
        count++;
      }
    }
  }
}

void evaluateGunshipMetroidLaserCollision(const CollisionInterface &collision,
                                          IGunship &gunship,
                                          const std::vector<ILaser *> &metroidLasers,
                                          ILaser &gunshipLaser,
                                          IText &livesText)
{
  for (auto metroidLaser : metroidLasers)
  {
    if (collision.haveCollided(gunship, *metroidLaser))
    {
      gunship.loseLife();
      gunship.resetPosition();
      gunshipLaser.reset();
      for (auto metroidLaser : metroidLasers)
      {
        metroidLaser->reset();
      }
      livesText.setString("Lives: " + std::to_string(gunship.getLives()));
      return;
    }
  }
}
