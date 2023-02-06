#include "../include/wrappers/iRenderWindow.hpp"
#include "../include/models/iLaserCannon.hpp"
#include "../include/models/iLaser.hpp"
#include "../include/models/invader.hpp"
#include <vector>

void drawObjects(IRenderWindow &window, const ILaserCannon &cannon, const ILaser &laser, std::vector<std::vector<Invader *>> &invaders)
{
  window.clear();
  cannon.draw(window);
  laser.draw(window);
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 11; j++)
    {
      invaders[i][j]->draw(window);
    }
  }
  window.display();
}
