#include "../../../include/models/iLaserCannon.hpp"
#include "../../../include/models/iLaser.hpp"

void playAgain(bool &isPlaying, bool &gameOver, ILaserCannon &cannon, ILaser &laser)
{
  isPlaying = true;
  gameOver = false;
  cannon.reset();
  laser.reset();
}
