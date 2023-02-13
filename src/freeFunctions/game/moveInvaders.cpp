#include <vector>
#include "../../../include/models/iInvader.hpp"
#include "../../../include/wrappers/iClock.hpp"
#include "../../../include/wrappers/iSound.hpp"

void moveInvaders(const std::vector<std::vector<IInvader *>> &invaders, IClock &clock, int &interval, int &step, std::vector<ISound *> &sounds, int &soundCounter)
{
  if (clock.getElapsedTime().asMilliseconds() >= interval * step)
  {
    for (auto vec : invaders)
    {
      for (auto invader : vec)
      {
        invader->move();
      }
    }
    if (invaders[0][0]->hasJustMovedDown())
    {
      clock.restart();
      interval -= 35;
      step = 1;
    }
    else
    {
      step++;
    }
    sounds[soundCounter % 4]->play();
    soundCounter++;
  }
}
