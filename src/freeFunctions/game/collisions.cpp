#include "../../../include/interfaces/collisionInterface.hpp"
#include "../../../include/models/IGunshipLaser.hpp"
#include "../../../include/models/IMetroidLaser.hpp"
#include "../../../include/models/IMetroid.hpp"
#include "../../../include/models/IRidley.hpp"
#include "../../../include/models/IBunker.hpp"
#include "../../../include/models/IGunship.hpp"
#include "../../../include/adaptors/IText.hpp"

void evaluateGunshipLaserMetroidCollision(const CollisionInterface &collision,
                                          IGunshipLaser &gunshipLaser,
                                          const std::array<std::array<IMetroid*, 11>, 5> &metroids,
                                          std::unordered_map<std::string, int> &variables,
                                          IText &scoreText,
                                          IText &highScoreText)
{
  for (auto row : metroids)
  {
    for (auto metroid : row)
    {
      if (metroid->isAlive() && collision.haveCollided(gunshipLaser, *metroid))
      {
        metroid->die();
        variables["score"] += metroid->getPoints();
        scoreText.setString("Score: " + std::to_string(variables["score"]));
        if (variables["score"] > variables["highScore"])
        {
          highScoreText.setString("High Score: " + std::to_string(variables["score"]));
        }
        gunshipLaser.resetPosition();
        return;
      }
    }
  }
}

void evaluateGunshipLaserRidleyCollision(const CollisionInterface &collision,
                                         IGunshipLaser &gunshipLaser,
                                         IRidley &ridley,
                                         std::unordered_map<std::string, int> &variables,
                                         IText &scoreText,
                                         IText &highScoreText)
{
  if (collision.haveCollided(gunshipLaser, ridley))
  {
    ridley.die();
    variables["score"] += ridley.getPoints();
    scoreText.setString("Score: " + std::to_string(variables["score"]));
    if (variables["score"] > variables["highScore"])
    {
      highScoreText.setString("High Score: " + std::to_string(variables["score"]));
    }
    gunshipLaser.resetPosition();
  }
}

void evaluateGunshipLaserBunkerCollision(const CollisionInterface &collision, IGunshipLaser &gunshipLaser, std::array<IBunker*, 4> &bunkers)
{
  for (auto bunker : bunkers)
  {
    if (bunker->getHealth() > 0 && collision.haveCollided(gunshipLaser, *bunker))
    {
      bunker->decreaseHealth();
      gunshipLaser.resetPosition();
      return;
    }
  }
}

void evaluateMetroidLaserBunkerCollision(const CollisionInterface &collision, const std::array<IMetroidLaser*, 3> &metroidLasers, std::array<IBunker*, 4> &bunkers)
{
  for (auto metroidLaser : metroidLasers)
  {
    int count {0};
    while (count < 4)
    {
      IBunker *bunker = bunkers[count];
      if (bunker->getHealth() > 0 && collision.haveCollided(*metroidLaser, *bunker))
      {
        bunker->decreaseHealth();
        metroidLaser->resetPosition();
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
                                          const std::array<IMetroidLaser*, 3> &metroidLasers,
                                          IGunshipLaser &gunshipLaser,
                                          IText &livesText)
{
  for (auto metroidLaser : metroidLasers)
  {
    if (collision.haveCollided(gunship, *metroidLaser))
    {
      gunship.loseLife();
      gunship.resetPosition();
      gunshipLaser.resetPosition();
      for (auto metroidLaser : metroidLasers)
      {
        metroidLaser->resetPosition();
      }
      livesText.setString("Lives: " + std::to_string(gunship.getLives()));
      return;
    }
  }
}
