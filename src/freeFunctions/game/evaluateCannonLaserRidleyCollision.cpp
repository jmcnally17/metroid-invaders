#include "../../../include/interfaces/collisionInterface.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iRidley.hpp"
#include "../../../include/wrappers/iText.hpp"

void evaluateCannonLaserRidleyCollision(const CollisionInterface &collision, ILaser &cannonLaser, IRidley &ridley, int &score, IText &scoreText)
{
  if (collision.haveCollided(cannonLaser, ridley))
  {
    ridley.die();
    score += ridley.getPoints();
    scoreText.setString("Score: " + std::to_string(score));
    cannonLaser.reset();
  }
}
