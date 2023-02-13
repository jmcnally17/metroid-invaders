#include <vector>
#include "../../../include/wrappers/iClock.hpp"
#include "../../../include/models/iLaserCannon.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iInvader.hpp"

void playAgain(bool &isPlaying,
               bool &gameOver,
               ILaserCannon &cannon,
               ILaser &laser,
               const std::vector<std::vector<IInvader *>> &invaders,
               int &interval,
               int &step,
               int &soundCounter,
               int &level,
               int &score,
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
  interval = 665;
  step = 1;
  soundCounter = 0;
  level = 1;
  score = 0;
  clock.restart();
}
