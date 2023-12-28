#include "../../../include/adaptors/IRenderWindow.hpp"
#include "../../../include/adaptors/IText.hpp"
#include "../../../include/models/IBunker.hpp"
#include "../../../include/models/IGunship.hpp"
#include "../../../include/models/IGunshipLaser.hpp"
#include "../../../include/models/IMetroidLaser.hpp"
#include "../../../include/models/IMetroid.hpp"
#include "../../../include/models/IRidley.hpp"

void drawObjects(IRenderWindow &window,
                 const std::unordered_map<std::string, ISprite*> &backgrounds,
                 const std::array<IBunker*, 4> &bunkers,
                 const IGunship &gunship,
                 const IGunshipLaser &gunshipLaser,
                 const std::array<std::array<IMetroid*, 11>, 5> &metroids,
                 const std::array<IMetroidLaser*, 3> &metroidLasers,
                 const IRidley &ridley,
                 const std::unordered_map<std::string, IText*> &textObjects,
                 const std::array<sf::RectangleShape, 2> &rectangles)
{
  window.clear();
  auto gameBackground {backgrounds.find("game")->second};
  window.draw(*gameBackground);
  for (auto bunker : bunkers)
  {
    bunker->draw(window);
  }
  gunship.draw(window);
  gunshipLaser.draw(window);
  for (auto row : metroids)
  {
    for (auto metroid : row)
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
  auto scoreText {textObjects.find("score")->second};
  auto highScoreText {textObjects.find("highScore")->second};
  auto livesText {textObjects.find("lives")->second};
  window.draw(*scoreText);
  window.draw(*highScoreText);
  window.draw(*livesText);
  for (auto rectangle : rectangles)
  {
    window.draw(rectangle);
  }
  window.display();
}
