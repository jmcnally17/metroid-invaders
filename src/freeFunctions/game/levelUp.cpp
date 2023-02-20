#include <vector>
#include "../../../include/models/iInvader.hpp"

void levelUp(int &level, int &interval, int &step, int &soundCounter, const std::vector<std::vector<IInvader *>> &invaders)
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
    }
  }
}
