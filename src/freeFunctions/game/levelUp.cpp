#include "../../../include/models/IMetroid.hpp"
#include "../../../include/models/IRidley.hpp"
#include "../../../include/adaptors/IClock.hpp"

void levelUp(std::unordered_map<std::string, int> &variables,
             const std::array<std::array<IMetroid*, 11>, 5> &metroids,
             const std::array<IMetroidLaser*, 3> &metroidLasers,
             IRidley &ridley,
             IClock &movementClock)
{
  variables["level"]++;
  variables["interval"] = 665;
  variables["step"] = 1;
  variables["soundCounter"] = 0;
  for (auto row : metroids)
  {
    for (auto metroid : row)
    {
      metroid->resurrect();
      if (metroid->getDirection() == -1)
      {
        metroid->changeDirection();
      }
      sf::Vector2f originalPosition {metroid->getOriginalPosition()};
      float originalXPosition {originalPosition.x};
      float originalYPosition {originalPosition.y};
      float levelUpShift = (variables["level"] - 1) * 42;
      sf::Vector2f levelUpPosition(originalXPosition, originalYPosition + levelUpShift);
      metroid->setPosition(levelUpPosition);
    }
  }
  for (auto metroidLaser : metroidLasers)
  {
    metroidLaser->resetPosition();
  }
  ridley.reset();
  ridley.stopMovementSoundIfPlaying();
  movementClock.restart();
}
