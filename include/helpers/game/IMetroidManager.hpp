#ifndef I_METROID_MANAGER_HPP
#define I_METROID_MANAGER_HPP

#include "../../adaptors/IClock.hpp"
#include "../../adaptors/ISound.hpp"
#include "../../models/IMetroid.hpp"
#include "../../models/IMetroidLaser.hpp"

class IMetroidManager
{
public:
  virtual bool areMetroidsDead(const std::array<std::array<IMetroid*, 11>, 5> &metroids) const = 0;
  virtual bool haveMetroidsInvaded(const std::array<std::array<IMetroid*, 11>, 5> &metroids) const = 0;
  virtual void moveMetroids(const std::array<std::array<IMetroid*, 11>, 5> &metroids, IClock &movementClock, std::unordered_map<std::string, int> &variables, const std::array<ISound*, 4> &sounds) const = 0;
  virtual void moveMetroidLasers(const std::array<IMetroidLaser*, 3> &metroidLasers) const = 0;
  virtual void shootMetroidLaser(const std::array<std::array<IMetroid*, 11>, 5> &metroids, const std::array<IMetroidLaser*, 3> &metroidLasers) const = 0;
};

#endif
