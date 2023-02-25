#include <vector>
#include "../../../include/wrappers/iRenderWindow.hpp"
#include "../../../include/wrappers/iText.hpp"
#include "../../../include/models/iLaserCannon.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iMetroid.hpp"

void drawObjects(IRenderWindow &window,
                 const ILaserCannon &cannon,
                 const ILaser &laser,
                 const std::vector<std::vector<IMetroid *>> &metroids,
                 const std::vector<ILaser *> &metroidLasers,
                 const IText &scoreText,
                 const IText &livesText)
{
  window.clear();
  cannon.draw(window);
  laser.draw(window);
  for (auto vec : metroids)
  {
    for (auto metroid : vec)
    {
      if (metroid->isAlive())
      {
        metroid->draw(window);
      }
    }
  }
  for (auto laser : metroidLasers)
  {
    laser->draw(window);
  }
  window.draw(scoreText);
  window.draw(livesText);
  window.display();
}
