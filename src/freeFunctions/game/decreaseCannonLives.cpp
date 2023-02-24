#include "../../../include/models/iLaserCannon.hpp"
#include "../../../include/models/iLaser.hpp"

void decreaseCannonLives(ILaserCannon &cannon, ILaser &cannonLaser)
{
  cannon.loseLife();
  cannon.resetPosition();
  cannonLaser.reset();
}
