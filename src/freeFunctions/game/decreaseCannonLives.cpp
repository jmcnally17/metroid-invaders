#include "../../../include/models/iLaserCannon.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/wrappers/iText.hpp"

void decreaseCannonLives(ILaserCannon &cannon, ILaser &cannonLaser, const std::vector<ILaser *> &invaderLasers, IText &livesText)
{
  cannon.loseLife();
  cannon.resetPosition();
  cannonLaser.reset();
  for (auto invaderLaser : invaderLasers)
  {
    invaderLaser->reset();
  }
  livesText.setString("Lives: " + std::to_string(cannon.getLives()));
}
