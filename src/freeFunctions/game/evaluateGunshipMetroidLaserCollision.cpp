#include "../../../include/interfaces/collisionInterface.hpp"
#include "../../../include/models/iGunship.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/wrappers/iText.hpp"

void evaluateGunshipMetroidLaserCollision(const CollisionInterface &collision,
                                         IGunship &gunship,
                                         const std::vector<ILaser *> &metroidLasers,
                                         ILaser &gunshipLaser,
                                         IText &livesText)
{
  for (auto metroidLaser : metroidLasers)
  {
    if (collision.haveCollided(gunship, *metroidLaser))
    {
      gunship.loseLife();
      gunship.resetPosition();
      gunshipLaser.reset();
      for (auto metroidLaser : metroidLasers)
      {
        metroidLaser->reset();
      }
      livesText.setString("Lives: " + std::to_string(gunship.getLives()));
      return;
    }
  }
}
