#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "./ICollision.hpp"

class Collision : public ICollision
{
public:
  void checkGunshipLaserBunkerCollision(IGunshipLaser &gunshipLaser, const std::array<IBunker*, 4> &bunkers) const override;
  void checkGunshipLaserMetroidCollision(IGunshipLaser &gunshipLaser, const std::array<std::array<IMetroid*, 11>, 5> &metroids, std::unordered_map<std::string, int> &variables, const std::unordered_map<std::string, IText*> &textObjects) const override;
  void checkGunshipLaserRidleyCollision(IGunshipLaser &gunshipLaser, IRidley &ridley, std::unordered_map<std::string, int> &variables, const std::unordered_map<std::string, IText*> &textObjects) const override;
  void checkGunshipMetroidLaserCollision(IGunship &gunship, const std::array<IMetroidLaser*, 3> &metroidLasers, IGunshipLaser &gunshipLaser, const std::unordered_map<std::string, IText*> &textObjects) const override;
  void checkMetroidLaserBunkerCollision(const std::array<IMetroidLaser*, 3> &metroidLasers, const std::array<IBunker*, 4> &bunkers) const override;
};

#endif
