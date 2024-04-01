#ifndef LEVEL_MANAGER_HPP
#define LEVEL_MANAGER_HPP

#include "./ILevelManager.hpp"

class LevelManager : public ILevelManager
{
public:
  void levelUp(std::unordered_map<std::string, int> &variables, const GameObjectList &gameObjects, IClock &movementClock) const override;
  void endGame(bool &isPlaying, bool &gameOver, IRidley &ridley, const std::unordered_map<std::string, ISound*> &themes) const override;
  void updateHighScore(std::unordered_map<std::string, int> &variables, const std::unordered_map<std::string, IText*> &textObjects) const override;
  void reset(const GameObjectList &gameObjects, bool &isPlaying, bool &gameOver, std::unordered_map<std::string, int> &variables, const std::unordered_map<std::string, IText*> &textObjects, const std::unordered_map<std::string, ISound*> &themes, IClock &movementClock) const override;
  void resetObjects(const GameObjectList &gameObjects) const override;
  void resetValues(bool &isPlaying, bool &gameOver, std::unordered_map<std::string, int> &variables) const override;
  void resetInformationObjects(const std::unordered_map<std::string, IText*> &textObjects, const std::unordered_map<std::string, ISound*> &themes, IClock &movementClock) const override;
};

#endif
