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
                  IClock &movementClock,
                  std::unordered_map<std::string, int> &variables,
                  std::vector<ISound *> &sounds)
{
  if (movementClock.getElapsedTime().asMilliseconds() >= variables["interval"] * variables["step"])
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
      movementClock.restart();
      variables["interval"] -= 35;
      variables["step"] = 1;
    }
    else
    {
      variables["step"]++;
    }
    sounds[variables["soundCounter"] % 4]->play();
    variables["soundCounter"]++;
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
