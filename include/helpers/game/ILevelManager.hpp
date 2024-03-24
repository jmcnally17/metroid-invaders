#ifndef I_LEVEL_MANAGER_HPP
#define I_LEVEL_MANAGER_HPP

#include "../../adaptors/IClock.hpp"
#include "../../adaptors/ISound.hpp"
#include "../../adaptors/IText.hpp"
#include "../../models/IBunker.hpp"
#include "../../models/IGunship.hpp"
#include "../../models/IGunshipLaser.hpp"
#include "../../models/IMetroid.hpp"
#include "../../models/IMetroidLaser.hpp"
#include "../../models/IRidley.hpp"

class ILevelManager
{
public:
  virtual void levelUp(std::unordered_map<std::string, int> &variables,
               const std::array<std::array<IMetroid*, 11>, 5> &metroids,
               const std::array<IMetroidLaser*, 3> &metroidLasers,
               IRidley &ridley,
               IClock &movementClock) const = 0;
  virtual void endGame(bool &isPlaying, bool &gameOver, IRidley &ridley, const std::unordered_map<std::string, ISound*> &themes) const = 0;
  virtual void updateHighScore(std::unordered_map<std::string, int> &variables, const std::unordered_map<std::string, IText*> &textObjects) const = 0;
  virtual void resetObjects(IGunship &gunship, IGunshipLaser &gunshipLaser,
                    const std::array<std::array<IMetroid*, 11>, 5> &metroids,
                    const std::array<IMetroidLaser*, 3> &metroidLasers,
                    IRidley &ridley,
                    const std::array<IBunker*, 4> &bunkers) const = 0;
  virtual void resetValues(bool &isPlaying, bool &gameOver, std::unordered_map<std::string, int> &variables) const = 0;
  virtual void resetInformationObjects(const std::unordered_map<std::string, IText*> &textObjects, const std::unordered_map<std::string, ISound*> &themes, IClock &movementClock) const = 0;
};

#endif
