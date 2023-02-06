#include "../include/models/iLaser.hpp"
#include "../include/models/iInvader.hpp"

bool hasInvaderBeenHit(ILaser &laser, IInvader &invader)
{
  bool condition1 = laser.getPosition().y + laser.getHeight() > invader.getPosition().y;
  return condition1;
}
