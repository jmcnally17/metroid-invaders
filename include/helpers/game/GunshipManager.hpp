#ifndef GUNSHIP_MANAGER_HPP
#define GUNSHIP_MANAGER_HPP

#include "../../models/IGunship.hpp"
#include "../../models/IGunshipLaser.hpp"

class GunshipManager
{
public:
  void moveGunship(IGunship &gunship, int direction) const;
  void moveGunshipLaser(IGunshipLaser &gunshipLaser) const;
  void fireGunshipLaser(IGunship &gunship) const;
};

#endif
