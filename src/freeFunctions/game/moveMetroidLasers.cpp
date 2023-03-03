#include <vector>
#include "../../../include/models/iLaser.hpp"

void moveMetroidLasers(const std::vector<ILaser *> &metroidLasers)
{
  for (auto metroidLaser : metroidLasers)
  {
    metroidLaser->move();
  }
}
