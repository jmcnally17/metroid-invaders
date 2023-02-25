#include <vector>
#include "../../../include/models/iMetroid.hpp"
#include "../../../include/wrappers/iClock.hpp"
#include "../../../include/wrappers/iSound.hpp"

void moveMetroids(const std::vector<std::vector<IMetroid *>> &metroids, IClock &clock, int &interval, int &step, std::vector<ISound *> &sounds, int &soundCounter)
{
  if (clock.getElapsedTime().asMilliseconds() >= interval * step)
  {
    for (auto vec : metroids)
    {
      for (auto metroid : vec)
      {
        metroid->move();
      }
    }
    if (metroids[0][0]->hasJustMovedDown())
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
