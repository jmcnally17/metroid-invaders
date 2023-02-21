#include <vector>
#include "../../../include/models/iInvader.hpp"
#include "../../../include/wrappers/iClock.hpp"

void levelUp(int &level, int &interval, int &step, int &soundCounter, const std::vector<std::vector<IInvader *>> &invaders, IClock &clock)
{
  level++;
  interval = 665;
  step = 1;
  soundCounter = 0;
  for (auto row : invaders)
  {
    for (auto invader : row)
    {
      invader->resurrect();
      invader->changeDirection();
      sf::Vector2f originalPosition = invader->getOriginalPosition();
      float originalXPosition = originalPosition.x;
      float originalYPosition = originalPosition.y;
      float levelUpShift = (level - 1) * 42;
      sf::Vector2f levelUpPosition(originalXPosition, originalYPosition + levelUpShift);
      invader->setPosition(levelUpPosition);
    }
  }
  clock.restart();
}
