#include "../../../include/models/iRidley.hpp"
#include "../../../include/wrappers/iText.hpp"

void evaluateLaserRidleyCollision(IRidley &ridley, int &score, IText &scoreText)
{
  ridley.die();
  score += ridley.getPoints();
  scoreText.setString("Score: " + std::to_string(score));
}
