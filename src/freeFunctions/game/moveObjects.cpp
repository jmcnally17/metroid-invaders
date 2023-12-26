#include "../../../include/models/IGunship.hpp"
#include "../../../include/models/IGunshipLaser.hpp"
#include "../../../include/models/IMetroid.hpp"
#include "../../../include/models/IMetroidLaser.hpp"
#include "../../../include/models/IRidley.hpp"
#include "../../../include/wrappers/IClock.hpp"
#include "../../../include/wrappers/ISound.hpp"

void moveGunship(IGunship &gunship, int direction)
{
  gunship.move(direction);
}

void moveGunshipLaser(IGunshipLaser &gunshipLaser)
{
  gunshipLaser.move();
}

void moveMetroids(const std::array<std::array<IMetroid*, 11>, 5> &metroids,
                  IClock &movementClock,
                  std::unordered_map<std::string, int> &variables,
                  std::array<ISound*, 4> &sounds)
{
  if (movementClock.getElapsedTime().asMilliseconds() >= variables["interval"] * variables["step"])
  {
    for (auto row : metroids)
    {
      for (auto metroid : row)
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

void moveMetroidLasers(const std::array<IMetroidLaser*, 3> &metroidLasers)
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
