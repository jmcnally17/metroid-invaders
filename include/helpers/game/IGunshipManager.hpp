#ifndef I_GUNSHIP_MANAGER_HPP
#define I_GUNSHIP_MANAGER_HPP

#include "../../models/IGunship.hpp"
#include "../../models/IGunshipLaser.hpp"

class IGunshipManager
{
public:
  virtual void moveGunship(IGunship &gunship, int direction) const = 0;
  virtual void moveGunshipLaser(IGunshipLaser &gunshipLaser) const = 0;
  virtual void fireGunshipLaser(IGunship &gunship) const = 0;
};

#endif
