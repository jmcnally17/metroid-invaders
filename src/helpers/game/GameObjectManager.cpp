#include "../../../include/helpers/game/GameObjectManager.hpp"

GameObjectManager::GameObjectManager(ICollision *collision, IGunshipManager *gunshipManager, ILevelManager *levelManager, IMetroidManager *metroidManager, IRidleyManager *ridleyManager) : collision_(collision), gunshipManager_(gunshipManager), levelManager_(levelManager), metroidManager_(metroidManager), ridleyManager_(ridleyManager) {}

void GameObjectManager::implementGameObjects(const std::array<IBunker*, 4> &bunkers, IGunship &gunship, IGunshipLaser &gunshipLaser, const std::array<std::array<IMetroid*, 11>, 5> &metroids, const std::array<IMetroidLaser*, 3> &metroidLasers, const std::array<ISound*, 4> &metroidSounds, IRidley &ridley, const std::unordered_map<std::string, IText*> &textObjects, const std::unordered_map<std::string, ISound*> &themes, std::unordered_map<std::string, int> &variables, bool &isPlaying, bool &gameOver, IClock &movementClock) const
{
  collision_->checkCollisions(bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, textObjects, variables);
  if (metroidManager_->haveMetroidsInvaded(metroids) || gunship.getLives() == 0)
  {
    levelManager_->endGame(isPlaying, gameOver, ridley, themes);
    levelManager_->updateHighScore(variables, textObjects);
  }
  ridleyManager_->monitorRidleyMovementSound(ridley);
  if (metroidManager_->areMetroidsDead(metroids))
  {
    levelManager_->levelUp(variables, metroids, metroidLasers, ridley, movementClock);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    gunshipManager_->moveGunship(gunship, 1);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    gunshipManager_->moveGunship(gunship, -1);
  }
  gunshipManager_->moveGunshipLaser(gunshipLaser);
  metroidManager_->moveMetroids(metroids, movementClock, variables, metroidSounds);
  metroidManager_->moveMetroidLasers(metroidLasers);
  ridleyManager_->moveRidley(ridley);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    gunshipManager_->fireGunshipLaser(gunship);
  }
  metroidManager_->shootMetroidLaser(metroids, metroidLasers);
  ridleyManager_->spawnRidley(ridley);
}
