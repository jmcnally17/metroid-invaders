#ifndef I_COLLISION_HPP
#define I_COLLISION_HPP

#include "../../models/IBunker.hpp"
#include "../../models/IGunship.hpp"
#include "../../models/IGunshipLaser.hpp"
#include "../../models/IMetroid.hpp"
#include "../../models/IMetroidLaser.hpp"
#include "../../models/IRidley.hpp"
#include "../../adaptors/IText.hpp"

class ICollision
{
public:
  virtual void checkGunshipLaserBunkerCollision(IGunshipLaser &gunshipLaser, const std::array<IBunker*, 4> &bunkers) const = 0;
  virtual void checkGunshipLaserMetroidCollision(IGunshipLaser &gunshipLaser, const std::array<std::array<IMetroid*, 11>, 5> &metroids, std::unordered_map<std::string, int> &variables, const std::unordered_map<std::string, IText*> &textObjects) const = 0;
  virtual void checkGunshipLaserRidleyCollision(IGunshipLaser &gunshipLaser, IRidley &ridley, std::unordered_map<std::string, int> &variables, const std::unordered_map<std::string, IText*> &textObjects) const = 0;
  virtual void checkGunshipMetroidLaserCollision(IGunship &gunship, const std::array<IMetroidLaser*, 3> &metroidLasers, IGunshipLaser &gunshipLaser, const std::unordered_map<std::string, IText*> &textObjects) const = 0;
  virtual void checkMetroidLaserBunkerCollision(const std::array<IMetroidLaser*, 3> &metroidLasers, const std::array<IBunker*, 4> &bunkers) const = 0;
};

#endif
