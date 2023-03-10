#include <vector>
#include "../../../include/models/iMetroid.hpp"
#include "../../../include/models/iRidley.hpp"
#include "../../../include/wrappers/iClock.hpp"

bool areMetroidsDead(const std::vector<std::vector<IMetroid *>> &metroids)
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

void levelUp(int &level,
             int &interval,
             int &step,
             int &soundCounter,
             const std::vector<std::vector<IMetroid *>> &metroids,
             const std::vector<ILaser *> &metroidLasers,
             IRidley &ridley,
             IClock &movementClock)
{
  level++;
  interval = 665;
  step = 1;
  soundCounter = 0;
  for (auto row : metroids)
  {
    for (auto metroid : row)
    {
      metroid->resurrect();
      if (metroid->getDirection() == -1)
      {
        metroid->changeDirection();
      }
      sf::Vector2f originalPosition = metroid->getOriginalPosition();
      float originalXPosition = originalPosition.x;
      float originalYPosition = originalPosition.y;
      float levelUpShift = (level - 1) * 42;
      sf::Vector2f levelUpPosition(originalXPosition, originalYPosition + levelUpShift);
      metroid->setPosition(levelUpPosition);
    }
  }
  for (auto metroidLaser : metroidLasers)
  {
    metroidLaser->reset();
  }
  ridley.reset();
  ridley.stopMovementSoundIfPlaying();
  movementClock.restart();
}
