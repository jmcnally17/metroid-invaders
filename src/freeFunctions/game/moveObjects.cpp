#include <vector>
#include "../../../include/models/iGunship.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iMetroid.hpp"
#include "../../../include/models/iRidley.hpp"
#include "../../../include/wrappers/iClock.hpp"
#include "../../../include/wrappers/iSound.hpp"

void moveGunship(IGunship &gunship, float x)
{
  gunship.move(x);
}

void moveGunshipLaser(ILaser &gunshipLaser)
{
  gunshipLaser.move();
}

void moveMetroids(const std::vector<std::vector<IMetroid *>> &metroids,
                  IClock &clock,
                  int &interval,
                  int &step,
                  std::vector<ISound *> &sounds,
                  int &soundCounter)
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

void moveMetroidLasers(const std::vector<ILaser *> &metroidLasers)
{
  for (auto metroidLaser : metroidLasers)
  {
    metroidLaser->move();
  }
}

void moveRidley(IRidley &ridley)
{
  ridley.move();
}
