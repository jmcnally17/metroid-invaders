#ifndef I_LEVEL_MANAGER_HPP
#define I_LEVEL_MANAGER_HPP

#include "../../struct/GameObjectList.hpp"
#include "../../adaptors/IClock.hpp"
#include "../../adaptors/ISound.hpp"
#include "../../adaptors/IText.hpp"

class ILevelManager
{
public:
  virtual void levelUp(std::unordered_map<std::string, int> &variables, const GameObjectList &gameObjects, IClock &movementClock) const = 0;
  virtual void endGame(bool &isPlaying, bool &gameOver, IRidley &ridley, const std::unordered_map<std::string, ISound*> &themes) const = 0;
  virtual void updateHighScore(std::unordered_map<std::string, int> &variables, const std::unordered_map<std::string, IText*> &textObjects) const = 0;
  virtual void reset(const GameObjectList &gameObjects, bool &isPlaying, bool &gameOver, std::unordered_map<std::string, int> &variables, const std::unordered_map<std::string, IText*> &textObjects, const std::unordered_map<std::string, ISound*> &themes, IClock &movementClock) const = 0;
  virtual void resetObjects(const GameObjectList &gameObjects) const = 0;
  virtual void resetValues(bool &isPlaying, bool &gameOver, std::unordered_map<std::string, int> &variables) const = 0;
  virtual void resetInformationObjects(const std::unordered_map<std::string, IText*> &textObjects, const std::unordered_map<std::string, ISound*> &themes, IClock &movementClock) const = 0;
};

#endif
