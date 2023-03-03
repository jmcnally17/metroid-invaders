#include <vector>
#include "../../../include/wrappers/iText.hpp"
#include "../../../include/wrappers/iClock.hpp"
#include "../../../include/models/iLaserCannon.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iMetroid.hpp"
#include "../../../include/models/iRidley.hpp"

void playAgain(bool &isPlaying,
               bool &gameOver,
               ILaserCannon &cannon,
               ILaser &cannonLaser,
               const std::vector<std::vector<IMetroid *>> &metroids,
               const std::vector<ILaser *> &metroidLasers,
               IRidley &ridley,
               int &interval,
               int &step,
               int &soundCounter,
               int &level,
               int &score,
               IText &scoreText,
               IText &livesText,
               IClock &clock)
{
  isPlaying = true;
  gameOver = false;
  cannon.reset();
  cannonLaser.reset();
  for (auto metroidRow : metroids)
  {
    for (auto metroid : metroidRow)
    {
      metroid->reset();
    }
  }
  for (auto metroidLaser : metroidLasers)
  {
    metroidLaser->reset();
  }
  ridley.reset();
  interval = 665;
  step = 1;
  soundCounter = 0;
  level = 1;
  score = 0;
  scoreText.setString("Score: 0");
  scoreText.setPosition(sf::Vector2f(20, 0));
  scoreText.setOrigin(0, 0);
  livesText.setString("Lives: " + std::to_string(cannon.getLives()));
  clock.restart();
}
