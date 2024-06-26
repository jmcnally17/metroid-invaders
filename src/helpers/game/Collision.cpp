#include "../../../include/helpers/game/Collision.hpp"

void Collision::checkCollisions(const GameObjectList &gameObjects, const std::unordered_map<std::string, IText *> &textObjects, std::unordered_map<std::string, int> &variables) const
{
  std::array<IBunker*, 4> bunkers {gameObjects.bunkers};
  IGunship *gunship {gameObjects.gunship};
  IGunshipLaser *gunshipLaser {gameObjects.gunshipLaser};
  std::array<std::array<IMetroid*, 11>, 5> metroids {gameObjects.metroids};
  std::array<IMetroidLaser*, 3> metroidLasers {gameObjects.metroidLasers};
  IRidley *ridley {gameObjects.ridley};
  checkGunshipLaserMetroidCollision(*gunshipLaser, metroids, variables, textObjects);
  checkGunshipLaserRidleyCollision(*gunshipLaser, *ridley, variables, textObjects);
  checkGunshipLaserBunkerCollision(*gunshipLaser, bunkers);
  checkMetroidLaserBunkerCollision(metroidLasers, bunkers);
  checkGunshipMetroidLaserCollision(*gunship, metroidLasers, *gunshipLaser, textObjects);
}

void Collision::checkGunshipLaserBunkerCollision(IGunshipLaser &gunshipLaser, const std::array<IBunker*, 4> &bunkers) const
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

void Collision::checkGunshipLaserMetroidCollision(IGunshipLaser &gunshipLaser, const std::array<std::array<IMetroid *, 11>, 5> &metroids, std::unordered_map<std::string, int> &variables, const std::unordered_map<std::string, IText *> &textObjects) const
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

void Collision::checkGunshipLaserRidleyCollision(IGunshipLaser &gunshipLaser, IRidley &ridley, std::unordered_map<std::string, int> &variables, const std::unordered_map<std::string, IText*> &textObjects) const
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

void Collision::checkGunshipMetroidLaserCollision(IGunship &gunship, const std::array<IMetroidLaser *, 3> &metroidLasers, IGunshipLaser &gunshipLaser, const std::unordered_map<std::string, IText *> &textObjects) const
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

void Collision::checkMetroidLaserBunkerCollision(const std::array<IMetroidLaser *, 3> &metroidLasers, const std::array<IBunker *, 4> &bunkers) const
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
