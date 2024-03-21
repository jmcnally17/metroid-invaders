#ifndef METROID_MANAGER_HPP
#define METROID_MANAGER_HPP

#include "../../adaptors/IClock.hpp"
#include "../../adaptors/ISound.hpp"
#include "../../models/IMetroid.hpp"
#include "../../models/IMetroidLaser.hpp"

class MetroidManager
{
public:
  bool areMetroidsDead(const std::array<std::array<IMetroid*, 11>, 5> &metroids) const;
  bool haveMetroidsInvaded(const std::array<std::array<IMetroid*, 11>, 5> &metroids) const;
  void moveMetroids(const std::array<std::array<IMetroid*, 11>, 5> &metroids,
                    IClock &movementClock,
                    std::unordered_map<std::string, int> &variables,
                    std::array<ISound*, 4> &sounds) const;
  void moveMetroidLasers(const std::array<IMetroidLaser*, 3> &metroidLasers) const;
  void shootMetroidLaser(const std::array<std::array<IMetroid*, 11>, 5> &metroids, const std::array<IMetroidLaser*, 3> &metroidLasers) const;
};

#endif
