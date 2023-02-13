#include <vector>
#include "../../../include/wrappers/iRenderWindow.hpp"
#include "../../../include/wrappers/iText.hpp"
#include "../../../include/models/iLaserCannon.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iInvader.hpp"

void drawObjects(IRenderWindow &window, const ILaserCannon &cannon, const ILaser &laser, const std::vector<std::vector<IInvader *>> &invaders, const IText &scoreText)
{
  window.clear();
  cannon.draw(window);
  laser.draw(window);
  for (auto vec : invaders)
  {
    for (auto IInvader : vec)
    {
      if (IInvader->isAlive())
      {
        IInvader->draw(window);
      }
    }
  }
  window.draw(scoreText);
  window.display();
}
