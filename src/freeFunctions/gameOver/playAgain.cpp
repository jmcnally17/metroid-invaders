#include "../../../include/adaptors/IText.hpp"
#include "../../../include/adaptors/ISound.hpp"
#include "../../../include/adaptors/IClock.hpp"
#include "../../../include/models/IGunship.hpp"
#include "../../../include/models/IGunshipLaser.hpp"
#include "../../../include/models/IMetroid.hpp"
#include "../../../include/models/IMetroidLaser.hpp"
#include "../../../include/models/IRidley.hpp"
#include "../../../include/models/IBunker.hpp"

void resetObjects(IGunship &gunship, IGunshipLaser &gunshipLaser,
                  const std::array<std::array<IMetroid*, 11>, 5> &metroids,
                  const std::array<IMetroidLaser*, 3> &metroidLasers,
                  IRidley &ridley,
                  const std::array<IBunker*, 4> &bunkers)
{
  gunship.reset();
  gunshipLaser.resetPosition();
  for (auto metroidRow : metroids)
  {
    for (auto metroid : metroidRow)
    {
      metroid->reset();
    }
  }
  for (auto metroidLaser : metroidLasers)
  {
    metroidLaser->resetPosition();
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

void resetInformationObjects(const std::unordered_map<std::string, IText*> &textObjects, const std::unordered_map<std::string, ISound*> &themes, IClock &movementClock)
{
  auto scoreText {textObjects.find("score")->second};
  auto livesText {textObjects.find("lives")->second};
  auto creditsTheme {themes.find("credits")->second};
  auto battleTheme {themes.find("battle")->second};
  scoreText->setString("Score: 0");
  scoreText->setPosition(sf::Vector2f(20, 0));
  scoreText->setOrigin(0, 0);
  livesText->setString("Lives: 3");
  creditsTheme->stop();
  battleTheme->play();
  movementClock.restart();
}
