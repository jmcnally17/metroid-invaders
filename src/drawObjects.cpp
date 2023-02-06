#include "../include/wrappers/iRenderWindow.hpp"
#include "../include/models/iLaserCannon.hpp"
#include "../include/models/iLaser.hpp"
#include "../include/models/iInvader.hpp"
#include <vector>

void drawObjects(IRenderWindow &window, const ILaserCannon &cannon, const ILaser &laser, const std::vector<std::vector<IInvader *>> &invaders)
{
  window.clear();
  cannon.draw(window);
  laser.draw(window);
  for (auto vec : invaders)
  {
    for (auto IInvader : vec)
    {
      IInvader->draw(window);
    }
  }
  window.display();
}
