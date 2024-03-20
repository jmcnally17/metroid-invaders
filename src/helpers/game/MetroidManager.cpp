#include "../../../include/helpers/game/MetroidManager.hpp"

bool MetroidManager::areMetroidsDead(const std::array<std::array<IMetroid*, 11>, 5> &metroids) const
{
  for (auto row : metroids)
  {
    for (auto metroid : row)
    {
      if (metroid->isAlive())
      {
        return false;
      }
    }
  }
  return true;
}

bool MetroidManager::haveMetroidsInvaded(const std::array<std::array<IMetroid*, 11>, 5> &metroids) const
{
  for (auto row : metroids)
  {
    for (auto metroid : row)
    {
      if (metroid->isAlive() && metroid->getPosition().y >= 1128)
      {
        return true;
      }
    }
  }
  return false;
}

void MetroidManager::moveMetroids(const std::array<std::array<IMetroid*, 11>, 5> &metroids,
                  IClock &movementClock,
                  std::unordered_map<std::string, int> &variables,
                  std::array<ISound*, 4> &sounds) const
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
