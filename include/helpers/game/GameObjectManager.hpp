#ifndef GAME_OBJECT_MANAGER_HPP
#define GAME_OBJECT_MANAGER_HPP

#include "../../struct/GameObjectList.hpp"
#include "./ICollision.hpp"
#include "./IGunshipManager.hpp"
#include "./ILevelManager.hpp"
#include "./IMetroidManager.hpp"
#include "./IRidleyManager.hpp"

class GameObjectManager
{
public:
  GameObjectManager(ICollision *collision, IGunshipManager *gunshipManager, ILevelManager *levelManager, IMetroidManager *metroidManager, IRidleyManager *ridleyManager);
  void implementGameObjects(const GameObjectList &gameObjects, const std::array<ISound*, 4> &metroidSounds, const std::unordered_map<std::string, IText*> &textObjects, const std::unordered_map<std::string, ISound*> &themes, std::unordered_map<std::string, int> &variables, bool &isPlaying, bool &gameOver, IClock &movementClock) const;
  
private:
  ICollision *collision_;
  IGunshipManager *gunshipManager_;
  ILevelManager *levelManager_;
  IMetroidManager *metroidManager_;
  IRidleyManager *ridleyManager_;
};

#endif
