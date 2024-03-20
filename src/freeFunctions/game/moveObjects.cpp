#include "../../../include/models/IMetroidLaser.hpp"

void moveMetroidLasers(const std::array<IMetroidLaser*, 3> &metroidLasers)
{
  for (auto metroidLaser : metroidLasers)
  {
    metroidLaser->move();
  }
}
