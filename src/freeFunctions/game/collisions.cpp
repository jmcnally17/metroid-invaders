#include "../../../include/models/IGunshipLaser.hpp"
#include "../../../include/models/IMetroidLaser.hpp"
#include "../../../include/models/IMetroid.hpp"
#include "../../../include/models/IRidley.hpp"
#include "../../../include/models/IBunker.hpp"
#include "../../../include/models/IGunship.hpp"
#include "../../../include/adaptors/IText.hpp"

void evaluateGunshipLaserMetroidCollision(IGunshipLaser &gunshipLaser,
                                          const std::array<std::array<IMetroid*, 11>, 5> &metroids,
                                          std::unordered_map<std::string, int> &variables,
                                          const std::unordered_map<std::string, IText*> &textObjects)
{
  for (auto row : metroids)
  {
    for (auto metroid : row)
    {
      if (metroid->isAlive() && gunshipLaser.intersects(*metroid))
      {
        metroid->die();
        variables["score"] += metroid->getPoints();
        auto scoreText {textObjects.find("score")->second};
        scoreText->setString("Score: " + std::to_string(variables["score"]));
        if (variables["score"] > variables["highScore"])
        {
          auto highScoreText {textObjects.find("highScore")->second};
          highScoreText->setString("High Score: " + std::to_string(variables["score"]));
        }
        gunshipLaser.resetPosition();
        return;
      }
    }
  }
}

void evaluateGunshipLaserRidleyCollision(IGunshipLaser &gunshipLaser,
                                         IRidley &ridley,
                                         std::unordered_map<std::string, int> &variables,
                                         const std::unordered_map<std::string, IText*> &textObjects)
{
  if (gunshipLaser.intersects(ridley))
  {
    ridley.die();
    variables["score"] += ridley.getPoints();
    auto scoreText {textObjects.find("score")->second};
    scoreText->setString("Score: " + std::to_string(variables["score"]));
    if (variables["score"] > variables["highScore"])
    {
      auto highScoreText {textObjects.find("highScore")->second};
      highScoreText->setString("High Score: " + std::to_string(variables["score"]));
    }
    gunshipLaser.resetPosition();
  }
}

void evaluateGunshipLaserBunkerCollision(IGunshipLaser &gunshipLaser, std::array<IBunker*, 4> &bunkers)
{
  for (auto bunker : bunkers)
  {
    if (bunker->getHealth() > 0 && gunshipLaser.intersects(*bunker))
    {
      bunker->decreaseHealth();
      gunshipLaser.resetPosition();
      return;
    }
  }
}

void evaluateMetroidLaserBunkerCollision(const std::array<IMetroidLaser*, 3> &metroidLasers, std::array<IBunker*, 4> &bunkers)
{
  for (auto metroidLaser : metroidLasers)
  {
    int count {0};
    while (count < 4)
    {
      IBunker *bunker = bunkers[count];
      if (bunker->getHealth() > 0 && metroidLaser->intersects(*bunker))
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

void evaluateGunshipMetroidLaserCollision(IGunship &gunship,
                                          const std::array<IMetroidLaser*, 3> &metroidLasers,
                                          IGunshipLaser &gunshipLaser,
                                          const std::unordered_map<std::string, IText*> &textObjects)
{
  for (auto metroidLaser : metroidLasers)
  {
    if (gunship.intersects(*metroidLaser))
    {
      gunship.loseLife();
      gunship.resetPosition();
      gunshipLaser.resetPosition();
      for (auto metroidLaser : metroidLasers)
      {
        metroidLaser->resetPosition();
      }
      auto livesText {textObjects.find("lives")->second};
      livesText->setString("Lives: " + std::to_string(gunship.getLives()));
      return;
    }
  }
}
