#include "../../../include/models/iLaserCannon.hpp"
#include "../../../include/models/iLaser.hpp"

void decreaseCannonLives(ILaserCannon &cannon, ILaser &cannonLaser, const std::vector<ILaser *> &invaderLasers)
{
  cannon.loseLife();
  cannon.resetPosition();
  cannonLaser.reset();
  for (auto invaderLaser : invaderLasers)
  {
    invaderLaser->reset();
  }
}
