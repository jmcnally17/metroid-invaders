#include "../../../include/interfaces/collisionInterface.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iRidley.hpp"
#include "../../../include/wrappers/iText.hpp"

void evaluateGunshipLaserRidleyCollision(const CollisionInterface &collision, ILaser &gunshipLaser, IRidley &ridley, int &score, IText &scoreText)
{
  if (collision.haveCollided(gunshipLaser, ridley))
  {
    ridley.die();
    score += ridley.getPoints();
    scoreText.setString("Score: " + std::to_string(score));
    gunshipLaser.reset();
  }
}
