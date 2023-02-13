#include "../../../include/models/iLaserCannon.hpp"

void playAgain(bool &isPlaying, bool &gameOver, ILaserCannon &cannon)
{
  isPlaying = true;
  gameOver = false;
  cannon.reset();
}
