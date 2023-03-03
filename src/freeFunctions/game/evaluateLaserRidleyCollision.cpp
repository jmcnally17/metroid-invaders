#include "../../../include/models/iRidley.hpp"

void evaluateLaserRidleyCollision(IRidley &ridley, int &score)
{
  ridley.die();
  score += ridley.getPoints();
}
