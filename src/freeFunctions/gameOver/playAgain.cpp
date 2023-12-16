#include "../../../include/wrappers/iText.hpp"
#include "../../../include/wrappers/iSound.hpp"
#include "../../../include/wrappers/iClock.hpp"
#include "../../../include/models/iGunship.hpp"
#include "../../../include/models/iLaser.hpp"
#include "../../../include/models/iMetroid.hpp"
#include "../../../include/models/iRidley.hpp"
#include "../../../include/models/iBunker.hpp"

void resetObjects(IGunship &gunship, ILaser &gunshipLaser,
                  const std::array<std::array<IMetroid*, 11>, 5> &metroids,
                  const std::array<ILaser*, 3> &metroidLasers,
                  IRidley &ridley,
                  const std::array<IBunker*, 4> &bunkers)
{
  gunship.reset();
  gunshipLaser.reset();
  for (auto metroidRow : metroids)
  {
    for (auto metroid : metroidRow)
    {
      metroid->reset();
    }
  }
  for (auto metroidLaser : metroidLasers)
  {
    metroidLaser->reset();
  }
  ridley.reset();
  for (auto bunker : bunkers)
  {
    bunker->reset();
  }
}

void resetValues(bool &isPlaying, bool &gameOver, std::unordered_map<std::string, int> &variables)
{
  isPlaying = true;
  gameOver = false;
  variables["interval"] = 665;
  variables["step"] = 1;
  variables["soundCounter"] = 0;
  variables["level"] = 1;
  variables["score"] = 0;
}

void resetInformationObjects(IText &scoreText, IText &livesText, ISound &creditsTheme, ISound &battleTheme, IClock &movementClock)
{
  scoreText.setString("Score: 0");
  scoreText.setPosition(sf::Vector2f(20, 0));
  scoreText.setOrigin(0, 0);
  livesText.setString("Lives: 3");
  creditsTheme.stop();
  battleTheme.play();
  movementClock.restart();
}
