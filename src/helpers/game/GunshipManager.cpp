#include "../../../include/helpers/game/GunshipManager.hpp"

void GunshipManager::moveGunship(IGunship &gunship, int direction) const
{
  gunship.move(direction);
}

void GunshipManager::moveGunshipLaser(IGunshipLaser &gunshipLaser) const
{
  gunshipLaser.move();
}

void GunshipManager::fireGunshipLaser(IGunship &gunship) const
{
  gunship.fire();
}
