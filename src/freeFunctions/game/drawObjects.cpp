#include <vector>
#include "../../../include/wrappers/iRenderWindow.hpp"
#include "../../../include/wrappers/iText.hpp"
#include "../../../include/models/iBunker.hpp"
#include "../../../include/models/iGunship.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iMetroid.hpp"
#include "../../../include/models/iRidley.hpp"

void drawObjects(IRenderWindow &window,
                 const ISprite &gameBackground,
                 const std::vector<IBunker *> &bunkers,
                 const IGunship &gunship,
                 const ILaser &gunshipLaser,
                 const std::vector<std::vector<IMetroid *>> &metroids,
                 const std::vector<ILaser *> &metroidLasers,
                 const IRidley &ridley,
                 const IText &scoreText,
                 const IText &highScoreText,
                 const IText &livesText,
                 const std::vector<sf::RectangleShape> &rectangles)
{
  window.clear();
  window.draw(gameBackground);
  for (auto bunker : bunkers)
  {
    bunker->draw(window);
  }
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
  window.draw(highScoreText);
  window.draw(livesText);
  for (auto rectangle : rectangles)
  {
    window.draw(rectangle);
  }
  window.display();
}
