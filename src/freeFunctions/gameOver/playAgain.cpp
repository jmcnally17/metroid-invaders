#include <vector>
#include "../../../include/wrappers/iText.hpp"
#include "../../../include/wrappers/iClock.hpp"
#include "../../../include/models/iLaserCannon.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iInvader.hpp"

void playAgain(bool &isPlaying,
               bool &gameOver,
               ILaserCannon &cannon,
               ILaser &laser,
               const std::vector<std::vector<IInvader *>> &invaders,
               const std::vector<ILaser *> &invaderLasers,
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
  laser.reset();
  for (auto invaderRow : invaders)
  {
    for (auto invader : invaderRow)
    {
      invader->reset();
    }
  }
  for (auto invaderLaser : invaderLasers)
  {
    invaderLaser->reset();
  }
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
