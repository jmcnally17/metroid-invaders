#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iRidley.hpp"
#include "../../../include/wrappers/iText.hpp"

void evaluateLaserRidleyCollision(ILaser &cannonLaser, IRidley &ridley, int &score, IText &scoreText)
{
  ridley.die();
  score += ridley.getPoints();
  scoreText.setString("Score: " + std::to_string(score));
  cannonLaser.reset();
}
