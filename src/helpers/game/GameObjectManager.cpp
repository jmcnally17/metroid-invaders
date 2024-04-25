#include "../../../include/helpers/game/GameObjectManager.hpp"

GameObjectManager::GameObjectManager(ICollision *collision, IGunshipManager *gunshipManager, ILevelManager *levelManager, IMetroidManager *metroidManager, IRidleyManager *ridleyManager) : collision_(collision), gunshipManager_(gunshipManager), levelManager_(levelManager), metroidManager_(metroidManager), ridleyManager_(ridleyManager) {}

void GameObjectManager::implementGameObjects(const GameObjectList &gameObjects, const std::array<ISound*, 4> &metroidSounds, const std::unordered_map<std::string, IText*> &textObjects, const std::unordered_map<std::string, ISound*> &themes, std::unordered_map<std::string, int> &variables, bool &isPlaying, bool &gameOver, IClock &movementClock) const
{
  collision_->checkCollisions(gameObjects, textObjects, variables);
  IGunship *gunship {gameObjects.gunship};
  IGunshipLaser *gunshipLaser {gameObjects.gunshipLaser};
  std::array<std::array<IMetroid*, 11>, 5> metroids {gameObjects.metroids};
  std::array<IMetroidLaser*, 3> metroidLasers {gameObjects.metroidLasers};
  IRidley *ridley {gameObjects.ridley};
  if (metroidManager_->haveMetroidsInvaded(metroids) || gunship->getLives() == 0)
  {
    levelManager_->endGame(isPlaying, gameOver, *ridley, themes);
    levelManager_->updateHighScore(variables, textObjects);
  }
  ridleyManager_->monitorRidleyMovementSound(*ridley);
  if (metroidManager_->areMetroidsDead(metroids))
  {
    levelManager_->levelUp(variables, gameObjects, movementClock);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    gunshipManager_->moveGunship(*gunship, 1);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    gunshipManager_->moveGunship(*gunship, -1);
  }
  gunshipManager_->moveGunshipLaser(*gunshipLaser);
  metroidManager_->moveMetroidLasers(metroidLasers);
  ridleyManager_->moveRidley(*ridley);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    gunshipManager_->fireGunshipLaser(*gunship);
  }
  metroidManager_->shootMetroidLaser(metroids, metroidLasers);
  ridleyManager_->spawnRidley(*ridley);
}
