#include <vector>
#include "../../include/models/iInvader.hpp"
#include "../../include/wrappers/iClock.hpp"

void moveInvaders(const std::vector<std::vector<IInvader *>> &invaders, IClock &clock, int &interval, int &step)
{
  for (auto vec : invaders)
  {
    for (auto invader : vec)
    {
      invader->move();
    }
  }
}
