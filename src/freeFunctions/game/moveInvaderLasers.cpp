#include <vector>
#include "../../../include/models/iLaser.hpp"

void moveInvaderLasers(const std::vector<ILaser *> &invaderLasers)
{
  for (auto laser : invaderLasers)
  {
    laser->move();
  }
}
