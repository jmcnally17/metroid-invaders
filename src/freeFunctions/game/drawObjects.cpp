#include <vector>
#include "../../../include/wrappers/iRenderWindow.hpp"
#include "../../../include/wrappers/iText.hpp"
#include "../../../include/models/iGunship.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iMetroid.hpp"
#include "../../../include/models/iRidley.hpp"

void drawObjects(IRenderWindow &window,
                 const IGunship &gunship,
                 const ILaser &gunshipLaser,
                 const std::vector<std::vector<IMetroid *>> &metroids,
                 const std::vector<ILaser *> &metroidLasers,
                 const IRidley &ridley,
                 const IText &scoreText,
                 const IText &livesText)
{
  window.clear();
  gunship.draw(window);
  gunshipLaser.draw(window);
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
  for (auto metroidLaser : metroidLasers)
  {
    metroidLaser->draw(window);
  }
  ridley.draw(window);
  window.draw(scoreText);
  window.draw(livesText);
  window.display();
}
