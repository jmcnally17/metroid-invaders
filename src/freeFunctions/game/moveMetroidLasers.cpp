#include <vector>
#include "../../../include/models/iLaser.hpp"

void moveMetroidLasers(const std::vector<ILaser *> &metroidLasers)
{
  for (auto laser : metroidLasers)
  {
    laser->move();
  }
}
