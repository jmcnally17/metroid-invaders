#ifndef METROID_MANAGER_HPP
#define METROID_MANAGER_HPP

#include "../../adaptors/IClock.hpp"
#include "../../adaptors/ISound.hpp"
#include "../../models/IMetroid.hpp"

class MetroidManager
{
public:
  bool areMetroidsDead(const std::array<std::array<IMetroid*, 11>, 5> &metroids) const;
  bool haveMetroidsInvaded(const std::array<std::array<IMetroid*, 11>, 5> &metroids) const;
  void moveMetroids(const std::array<std::array<IMetroid*, 11>, 5> &metroids,
                    IClock &movementClock,
                    std::unordered_map<std::string, int> &variables,
                    std::array<ISound*, 4> &sounds) const;
};

#endif
