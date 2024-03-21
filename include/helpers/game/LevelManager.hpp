#ifndef LEVEL_MANAGER_HPP
#define LEVEL_MANAGER_HPP

#include "../../adaptors/IClock.hpp"
#include "../../adaptors/ISound.hpp"
#include "../../adaptors/IText.hpp"
#include "../../models/IBunker.hpp"
#include "../../models/IGunship.hpp"
#include "../../models/IGunshipLaser.hpp"
#include "../../models/IMetroid.hpp"
#include "../../models/IMetroidLaser.hpp"
#include "../../models/IRidley.hpp"

class LevelManager
{
public:
  void levelUp(std::unordered_map<std::string, int> &variables,
               const std::array<std::array<IMetroid*, 11>, 5> &metroids,
               const std::array<IMetroidLaser*, 3> &metroidLasers,
               IRidley &ridley,
               IClock &movementClock) const;
  void endGame(bool &isPlaying, bool &gameOver, IRidley &ridley, std::unordered_map<std::string, ISound*> &themes) const;
  void updateHighScore(std::unordered_map<std::string, int> &variables, const std::unordered_map<std::string, IText*> &textObjects) const;
  void resetObjects(IGunship &gunship, IGunshipLaser &gunshipLaser,
                    const std::array<std::array<IMetroid*, 11>, 5> &metroids,
                    const std::array<IMetroidLaser*, 3> &metroidLasers,
                    IRidley &ridley,
                    const std::array<IBunker*, 4> &bunkers) const;
  void resetValues(bool &isPlaying, bool &gameOver, std::unordered_map<std::string, int> &variables) const;
  void resetInformationObjects(const std::unordered_map<std::string, IText*> &textObjects, const std::unordered_map<std::string, ISound*> &themes, IClock &movementClock) const;
};

#endif
