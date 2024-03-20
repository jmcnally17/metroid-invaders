#include "../../../include/models/IGunship.hpp"
#include "../../../include/models/IGunshipLaser.hpp"
#include "../../../include/models/IMetroidLaser.hpp"

void moveGunship(IGunship &gunship, int direction)
{
  gunship.move(direction);
}

void moveGunshipLaser(IGunshipLaser &gunshipLaser)
{
  gunshipLaser.move();
}

void moveMetroidLasers(const std::array<IMetroidLaser*, 3> &metroidLasers)
{
  for (auto metroidLaser : metroidLasers)
  {
    metroidLaser->move();
  }
}
