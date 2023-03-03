#include "../../../include/interfaces/collisionInterface.hpp"
#include "../../../include/models/iLaserCannon.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/wrappers/iText.hpp"

void evaluateCannonMetroidLaserCollision(const CollisionInterface &collision,
                                         ILaserCannon &cannon,
                                         const std::vector<ILaser *> &metroidLasers,
                                         ILaser &cannonLaser,
                                         IText &livesText)
{
  for (auto metroidLaser : metroidLasers)
  {
    if (collision.haveCollided(cannon, *metroidLaser))
    {
      cannon.loseLife();
      cannon.resetPosition();
      cannonLaser.reset();
      for (auto metroidLaser : metroidLasers)
      {
        metroidLaser->reset();
      }
      livesText.setString("Lives: " + std::to_string(cannon.getLives()));
      return;
    }
  }
}
