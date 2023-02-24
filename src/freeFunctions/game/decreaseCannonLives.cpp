#include "../../../include/models/iLaserCannon.hpp"

void decreaseCannonLives(ILaserCannon &cannon)
{
  cannon.loseLife();
  cannon.resetPosition();
}
