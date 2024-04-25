#ifndef GUNSHIP_MANAGER_HPP
#define GUNSHIP_MANAGER_HPP

#include "./IGunshipManager.hpp"

class GunshipManager : public IGunshipManager
{
public:
  void moveGunship(IGunship &gunship, int direction) const override;
  void moveGunshipLaser(IGunshipLaser &gunshipLaser) const override;
  void fireGunshipLaser(IGunship &gunship) const override;
};

#endif
