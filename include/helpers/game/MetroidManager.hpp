#ifndef METROID_MANAGER_HPP
#define METROID_MANAGER_HPP

#include "./IMetroidManager.hpp"

class MetroidManager : public IMetroidManager
{
public:
  bool areMetroidsDead(const std::array<std::array<IMetroid*, 11>, 5> &metroids) const override;
  bool haveMetroidsInvaded(const std::array<std::array<IMetroid*, 11>, 5> &metroids) const override;
  void moveMetroids(const std::array<std::array<IMetroid*, 11>, 5> &metroids,
                    IClock &movementClock,
                    std::unordered_map<std::string, int> &variables,
                    const std::array<ISound*, 4> &sounds) const override;
  void moveMetroidLasers(const std::array<IMetroidLaser*, 3> &metroidLasers) const override;
  void shootMetroidLaser(const std::array<std::array<IMetroid*, 11>, 5> &metroids, const std::array<IMetroidLaser*, 3> &metroidLasers) const override;
};

#endif
